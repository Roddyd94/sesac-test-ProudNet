#include "Client.h"

/* Protects all variable here.
If you are developing a game program or an app with fast-running loop,
this is not needed, as you are making a single threaded app.
This is required as this sample program uses two threads.
One is for waiting user input, the other is for processing
received messages and events. */
CriticalSection g_critSec;

TestGame::StubFunctional g_GameStub;

/* Client-to-server RMI proxy.
RMI proxy is used for sending messages aka.
calling a function which resides other process.
*/
TestGame::Proxy g_GameProxy;

// 내 플레이어 번호
int my_player_no = -1;

int cur_x = CENTER_X, cur_y = CENTER_Y;

int points[MAX_PLAYERS] = {
    0,
};
char maps[MAX_PLAYERS][TILE_ROW][TILE_COL] = {
    ' ',
};

int main(int argc, char *argv[]) {
  // Network client object.
  shared_ptr<CNetClient> netClient(CNetClient::Create());

  // set to false to exit the main loop.
  volatile bool keepWorkerThread = true;
  // set to true if server connection is established.
  bool isConnected = false;
  // changed if another P2P peer joined.
  HostID recentP2PGroupHostID = HostID_None;

  // 내 정보 수신 이벤트 처리 함수
  g_GameStub.WhoYouAre_Function = [] PARAM_TestGame_WhoYouAre {
    my_player_no = player_no;
    return true;
  };

  // 서버 아이템 정보 전송 이벤트 처리 함수
  g_GameStub.SendItems_Function = [] PARAM_TestGame_SendItems {
    for (auto i = items.begin(); i != items.end(); ++i) {
      maps[player_no][i->pos_x][i->pos_y] = '$';
    }
    return true;
  };

  // 서버 플레이어 정보 전송 이벤트 처리 함수
  g_GameStub.SendPlayerInfo_Function = [] PARAM_TestGame_SendPlayerInfo {
    maps[player_no][cur_x][cur_y] = ' ';

    // 점수
    points[player_no] = info.points;

    maps[player_no][info.pos_x][info.pos_y] = '@';
    cur_x = info.pos_x;
    cur_y = info.pos_y;

    return true;
  };

  // set a routine which is run when the server connection attempt
  // is success or failed.
  netClient->OnJoinServerComplete = [&](ErrorInfo *info,
                                        const ByteArray &replyFromServer) {
    // as here is running in 2nd thread, lock is needed for console print.
    CriticalSectionLock lock(g_critSec, true);

    if (info->m_errorType == ErrorType_Ok) {
      // connection successful.
      printf("Succeed to connect server. Allocated hostID=%d\n",
             netClient->GetLocalHostID());
      isConnected = true;

    } else {
      // connection failure.
      cout << "Failed to connect to server.\n";
    }
    g_GameProxy.WhoAmI(HostID_Server, RmiContext::FastEncryptedReliableSend);
  };

  // set a routine for network disconnection.
  netClient->OnLeaveServer = [&](ErrorInfo *errorInfo) {
    // lock is needed as above.
    CriticalSectionLock lock(g_critSec, true);

    // let main loop exit
    isConnected = false;
    keepWorkerThread = false;
  };

  // attach RMI proxy and stub to client object.
  netClient->AttachProxy(&g_GameProxy);
  netClient->AttachStub(&g_GameStub);

  CNetConnectionParam cp;

  // Protocol version which have to be same to the value at the server.
  cp.m_protocolVersion = g_Version;
  cp.m_closeNoPingPongTcpConnections = false;

  // server address
  if (argc > 1) {
    cp.m_serverIP = StringA2T(argv[1]);
  } else {
    cp.m_serverIP = _PNT("localhost");
  }

  // server port
  cp.m_serverPort = g_ServerPort;

  netClient->Connect(cp);

  // As we have to be notified events and message receivings,
  // We call FrameMove function for every short interval.
  // If you are developing a game, call FrameMove
  // without doing any sleep.
  // If you are developing an app, call FrameMove
  // in another thread or your timer callback routine.
  Proud::Thread workerThread([&]() {
    while (keepWorkerThread) {
      system("cls");
      for (int player = 0; player < MAX_PLAYERS; ++player) {
        string s;
        cout << "[" << (char)(my_player_no == player ? '*' : ' ') << "]Player "
             << player + 1 << ":" << points[player];

        for (int y = 0; y < TILE_ROW; ++y) {
          cout << '\n';
          for (int x = 0; x < TILE_COL; ++x) {
            cout << "[ " << maps[player][x][y] << " ]";
          }
        }

        cout << '\n';
        cout << '\n';
      }

      Proud::Sleep(100);

      // process received RMI and events.
      netClient->FrameMove();
    }
  });

  workerThread.Start();

  while (keepWorkerThread) {
    char key;
    // get user input
#ifdef _WIN32
    while (!_kbhit())
      ; // wait for input
    key = _getch();

#elif __unix__

#elif __linux__

#elif __APPLE__

#endif
    g_GameProxy.Move(HostID_Server, RmiContext::FastEncryptedReliableSend, key);
  }

  // Waits for 2nd thread exits.
  workerThread.Join();

  // Disconnects.
  // Note: deleting NetClient object automatically does it.
  netClient->Disconnect();

  return 0;
}
