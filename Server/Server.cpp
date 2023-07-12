#include "Server.h"
#include <stdlib.h>

// Server-to-client RMI stub
TestGame::StubFunctional g_GameStub;

// Server-to-client RMI proxy
TestGame::Proxy g_GameProxy;

// a P2P 그룹, 매치메이킹 클래스로 분리 필요
HostID g_groupHostID;

// 게임 데이터 관리 클래스로 분리 필요
bool game_started = false;
set<int> set_player;
map<HostID, int> map_HostID_player;
map<int, PlayerInfo> map_player_PlayerInfo;
map<int, vector<Item>> map_player_Items;

int main(int argc, char *argv[]) {
  // 랜덤 시드 세팅
  srand(time(nullptr));

  // 서버 인스턴스 생성
  shared_ptr<CNetServer> srv(CNetServer::Create());

  // 게임 그룹 생성, 나중에 매치메이킹 클래스로 분리
  g_groupHostID = srv->CreateP2PGroup();

  // 클라이언트 이동 동작 이벤트 처리 함수
  g_GameStub.WhoAmI_Function = [&srv] PARAM_TestGame_WhoAmI {
    int player_no = map_HostID_player[remote];
    g_GameProxy.WhoYouAre(remote, RmiContext::FastEncryptedReliableSend,
                          player_no);
    return true;
  };
  // 클라이언트 이동 동작 이벤트 처리 함수
  g_GameStub.Move_Function = [&srv] PARAM_TestGame_Move {
    // 게임 참여 확인
    if (map_HostID_player.find(remote) == map_HostID_player.end())
      return true;
    int player_no = map_HostID_player[remote];

    // 게임 중인지 확인
    if (!game_started)
      return true;

    // 플레이어 이동 확인
    bool player_moved = map_player_PlayerInfo[player_no].SetPosition(key);
    if (!player_moved)
      return true;

    // 이동 처리 및 아이템, 점수 갱신
    vector<Item> player_items = map_player_Items[player_no];
    PlayerInfo player_info = map_player_PlayerInfo[player_no];
    for (vector<Item>::iterator i = player_items.begin();
         i != player_items.end(); ++i) {
      if (i->pos_x != player_info.pos_x || i->pos_y != player_info.pos_y)
        continue;
      player_items.erase(i);
      player_info.AddPoint();
      break;
    }

    // 다른 플레이어에게 코인 전달, 가능하면 함수로 분리
    // 코인을 받을 다음 플레이어 선정
    int next_player = rand() % (set_player.size() - 1);
    // 현재 플레이어에게 코인이 가지 않도록
    if (next_player >= player_no)
      next_player++;
    // 다음 플레이어 정보
    vector<Item> next_player_items = map_player_Items[next_player];
    PlayerInfo next_player_info = map_player_PlayerInfo[next_player];
    // 다음 코인 위치
    int next_coin_x, next_coin_y;
    do {
      next_coin_x = rand() % TILE_COL;
      next_coin_y = rand() % TILE_ROW;
    } while (next_player_info.pos_x == next_coin_x &&
             next_player_info.pos_y == next_coin_y);
    // 코인 생성
    next_player_items.push_back(Item(next_coin_x, next_coin_y));

    // 그룹 내 플레이어에게 업데이트 정보 전송
    g_GameProxy.SendPlayerInfo(g_groupHostID,
                               RmiContext::FastEncryptedReliableSend, player_no,
                               player_info);
    g_GameProxy.SendItems(g_groupHostID, RmiContext::FastEncryptedReliableSend,
                          player_no, player_items);
    g_GameProxy.SendItems(g_groupHostID, RmiContext::FastEncryptedReliableSend,
                          next_player, next_player_items);

    return true;
  };

  // set a routine which is executed when a client is joining.
  // clientInfo has the client info including its HostID.
  srv->OnClientJoin = [&srv](CNetClientInfo *clientInfo) {
    HostID remote = clientInfo->m_HostID;

    // 게임 참여 인원 확인
    if (set_player.size() >= MAX_PLAYERS) {
      srv->CloseConnection(remote);
      return;
    }

    // p2p 그룹에 추가
    srv->JoinP2PGroup(remote, g_groupHostID);

    // 플레이어 번호 부여(0부터!), 게임 관리자 클래스로 분리 필요
    int player_no = -1;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
      if (set_player.find(i) != set_player.end())
        continue;
      player_no = i;
    }
    if (player_no == -1)
      return;

    // 플레이어 정보 등록, 게임 관리자 클래스로 분리 필요
    set_player.insert(player_no);
    map_HostID_player[remote] = player_no;
    map_player_Items.insert({player_no, vector<Item>()});
    map_player_PlayerInfo.insert({player_no, PlayerInfo()});

    // 플레이어 2명 이상 시 게임 시작
    if (set_player.size() >= 2) {
      game_started = true;
      map_player_Items[0].push_back(Item());
    }
  };

  // set a routine for client leave event.
  srv->OnClientLeave = [&srv](CNetClientInfo *clientInfo, ErrorInfo *errorInfo,
                              const ByteArray &comment) {
    HostID remote = clientInfo->m_HostID;

    // p2p 그룹에서 삭제
    srv->LeaveP2PGroup(remote, g_groupHostID);

    // 플레이어 정보 삭제
    int player_no = map_HostID_player[remote];
    set_player.erase(player_no);
    map_HostID_player.erase(remote);
    map_player_Items.erase(player_no);
    map_player_PlayerInfo.erase(player_no);

    // 플레이어 2명 미만 시 게임 종료
    if (set_player.size() < 2) {
      game_started = false;

      // 기존 플레이어 정보 초기화
      for (set<int>::const_iterator i = set_player.begin();
           i != set_player.end(); ++i) {
        map_player_Items[player_no] = vector<Item>();
        map_player_PlayerInfo[player_no] = PlayerInfo();
      }
    }

    // 모든 플레이어에게 정보 전송
    for (set<int>::const_iterator i = set_player.begin(); i != set_player.end();
         ++i) {
      g_GameProxy.SendItems(g_groupHostID,
                            RmiContext::FastEncryptedReliableSend, *i,
                            map_player_Items[*i]);
      g_GameProxy.SendPlayerInfo(g_groupHostID,
                                 RmiContext::FastEncryptedReliableSend, *i,
                                 map_player_PlayerInfo[*i]);
    }
  };

  // Associate RMI proxy and stub instances to network object.
  srv->AttachStub(&g_GameStub);
  srv->AttachProxy(&g_GameProxy);

  CStartServerParameter p1;
  p1.m_protocolVersion = g_Version; // This must be the same to the client.
  p1.m_tcpPorts.Add(g_ServerPort);  // TCP listening endpoint

  ErrorInfoPtr err;
  try {
    /* Starts the server.
    This function throws an exception on failure.
    Note: As we specify nothing for threading model,
    RMI function by message receive and event callbacks are
    called in a separate thread pool.
    You can change the thread model. Check out the help pages for details. */
    srv->Start(p1);
  } catch (Exception &e) {
    cout << "Server start failed: " << e.what() << endl;
    return 0;
  }

  while (true) {
    // get user input
    string userInput;
    cin >> userInput;

    // if ( userInput == "1" )
    // {
    // 	// get all client HostID array.
    // 	vector<HostID> clients;
    // 	int noofClients = srv->GetClientCount();
    // 	clients.resize(noofClients);
    // 	int listCount = srv->GetClientHostIDs(&clients[0], noofClients);

    // 	// create a P2P group where all clients are in.
    // 	g_groupHostID = srv->CreateP2PGroup(&clients[0], clients.size());
    // }
    // else if (userInput == "2")
    // {
    // 	// send an RMI message to every client.
    // 	g_SimpleProxy.SystemChat(g_groupHostID, RmiContext::ReliableSend,
    // _PNT("Hello~~~!"));
    // }
    // else if (userInput == "3")
    // {
    // 	// destroy the P2P group.
    // 	srv->DestroyP2PGroup(g_groupHostID);
    // 	g_groupHostID = HostID_None;
    // }
    // else if (userInput == "q")
    // {
    // 	// exit program.
    // 	break;
    // }
  }

  return 0;
}
