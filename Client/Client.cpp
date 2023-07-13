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

int main(int argc, char *argv[]) {
  // Network client object.
  shared_ptr<CNetClient> netClient(CNetClient::Create());

  // set to false to exit the main loop.
  volatile bool keepWorkerThread = true;
  // set to true if server connection is established.
  bool isConnected = false;
  // changed if another P2P peer joined.
  HostID recentP2PGroupHostID = HostID_None;

  // 게임 정보 초기화
  ClientGameManager &client_game_manager = ClientGameManager::get_instance();
  ClientUI &client_ui = ClientUI::get_instance();

  // 내 정보 수신 이벤트 처리 함수
  g_GameStub.WhoYouAre_Function =
      [&client_game_manager] PARAM_TestGame_WhoYouAre {
        client_game_manager.my_nth = player_nth;
        return true;
      };

  // 서버 아이템 정보 전송 이벤트 처리 함수
  g_GameStub.SendItemSet_Function =
      [&client_game_manager] PARAM_TestGame_SendItemSet {
        client_game_manager.item_set_array[player_nth] = item_set;
        return true;
      };

  // 서버 플레이어 정보 전송 이벤트 처리 함수
  g_GameStub.SendPlayer_Function =
      [&client_game_manager] PARAM_TestGame_SendPlayer {
        client_game_manager.player_array[player_nth] = player;
        return true;
      };

  // set a routine which is run when the server connection attempt
  // is success or failed.
  netClient->OnJoinServerComplete = [&](ErrorInfo *player,
                                        const ByteArray &replyFromServer) {
    // as here is running in 2nd thread, lock is needed for console print.
    CriticalSectionLock lock(g_critSec, true);

    if (player->m_errorType == ErrorType_Ok) {
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

  netClient->OnP2PMemberJoin = [&](HostID memberHostID, HostID groupHostID,
                                   int memberCount,
                                   const ByteArray &customField) {};

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
      client_ui.PrintGame(client_game_manager);
      Proud::Sleep(20);

      // process received RMI and events.
      netClient->FrameMove();
    }
  });

  workerThread.Start();

  while (keepWorkerThread) {
    bool pressed_right_key = false;
    int key;
    // get user input
#ifdef _WIN32
    while (!_kbhit())
      ; // wait for input
    key = _getch();
    switch (key) {
    case 'w':
    case 'W':
    case 's':
    case 'S':
    case 'a':
    case 'A':
    case 'd':
    case 'D':
      pressed_right_key = true;
      break;
    }
#elif __unix__
    cout << "unix test";

#elif __linux__
    cout << "linux test";

#elif __APPLE__

#endif
    if (pressed_right_key)
      g_GameProxy.Move(HostID_Server, RmiContext::FastEncryptedReliableSend,
                       key);

    Proud::Sleep(30);
  }

  // Waits for 2nd thread exits.
  workerThread.Join();

  // Disconnects.
  // Note: deleting NetClient object automatically does it.
  netClient->Disconnect();

  return 0;
}
