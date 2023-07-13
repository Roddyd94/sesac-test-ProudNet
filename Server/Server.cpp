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
map<int, Player> map_player_Player;
map<int, set<Item>> map_player_Items;

int main(int argc, char *argv[]) {
  // 랜덤 시드 세팅
  srand(time(nullptr));

  // 서버 인스턴스 생성
  shared_ptr<CNetServer> srv(CNetServer::Create());

  // 게임 그룹 생성, 나중에 매치메이킹 클래스로 분리
  g_groupHostID = srv->CreateP2PGroup();

  // 클라이언트 이동 동작 이벤트 처리 함수
  g_GameStub.WhoAmI_Function = [&srv] PARAM_TestGame_WhoAmI {
    int player_nth = map_HostID_player[remote];
    g_GameProxy.WhoYouAre(remote, RmiContext::FastEncryptedReliableSend,
                          player_nth);
    cout << "You are Player " << player_nth << ", " << (int)remote << '\n';
    return true;
  };
  // 클라이언트 이동 동작 이벤트 처리 함수
  g_GameStub.Move_Function = [&srv] PARAM_TestGame_Move {
    cout << "Move():\n";
    // 게임 참여 확인
    if (map_HostID_player.find(remote) == map_HostID_player.end())
      return true;
    int player_nth = map_HostID_player[remote];
    cout << "호스트 참여 확인\n";

    // 게임 중인지 확인
    if (!game_started)
      return true;
    cout << "게임 시작 확인\n";

    // 플레이어 이동 확인
    Player &player = map_player_Player[player_nth];
    if (!player.IsMovable(key))
      return true;
    cout << "플레이어 이동 가능성 확인\n";

    player.MoveToward(key);
    cout << "플레이어 이동\n";

    cout << "Player " << player_nth << " moved " << (char)key << " side!"
         << "and now at [" << player.pos_x << "," << player.pos_y << "]\n";

    // 이동 처리 및 아이템, 점수 갱신
    bool got_item = false;
    set<Item> &player_items = map_player_Items[player_nth];
    Player &player_player = map_player_Player[player_nth];
    for (set<Item>::iterator i = player_items.begin(); i != player_items.end();
         ++i) {
      cout << "Item located at " << i->pos_x << ", " << i->pos_y << "\n";
      if (i->pos_x != player_player.pos_x || i->pos_y != player_player.pos_y)
        continue;
      cout << "Player " << player_nth << " get item located at " << i->pos_x
           << ", " << i->pos_y << "\n";
      player_items.erase(i);
      player_player.AddPoint();
      got_item = true;
      cout << "Player's point is now " << player_player.points << "\n";
      break;
    }

    // 그룹 내 플레이어에게 업데이트 정보 전송
    g_GameProxy.SendPlayer(g_groupHostID, RmiContext::FastEncryptedReliableSend,
                           player_nth, player_player);

    // 현재 플레이어가 아이템을 먹었는지 확인
    if (got_item)
      return true;
    // 다른 플레이어에게 코인 전달, 가능하면 함수로 분리
    // 코인을 받을 다음 플레이어 선정
    int next_player;
    do {
      next_player = rand() % (set_player.size() - 1);
      // 현재 플레이어에게 코인이 가지 않도록
      if (next_player >= player_nth)
        next_player++;
    } while (map_player_Items[next_player].size() >= TILE_COL * TILE_ROW - 1);
    // 다음 플레이어 정보
    set<Item> &next_player_items = map_player_Items[next_player];
    Player &next_player_player = map_player_Player[next_player];
    // 다음 코인 위치
    int next_coin_x, next_coin_y;
    do {
      next_coin_x = rand() % TILE_COL;
      next_coin_y = rand() % TILE_ROW;
    } while (next_player_player.pos_x == next_coin_x &&
             next_player_player.pos_y == next_coin_y);
    // 코인 생성
    next_player_items.insert(Item(next_coin_x, next_coin_y));

    // 그룹 내 플레이어에게 업데이트 정보 전송
    g_GameProxy.SendItemSet(g_groupHostID,
                            RmiContext::FastEncryptedReliableSend, player_nth,
                            player_items);
    g_GameProxy.SendItemSet(g_groupHostID,
                            RmiContext::FastEncryptedReliableSend, next_player,
                            next_player_items);

    return true;
  };

  // set a routine which is executed when a client is joining.
  // clientInfo has the client player including its HostID.
  srv->OnClientJoin = [&srv](CNetClientInfo *clientInfo) {
    HostID remote = clientInfo->m_HostID;

    // 게임 참여 인원 확인
    if (set_player.size() >= MAX_PLAYERS) {
      srv->CloseConnection(remote);
      cout << "Players full, Bye~ PlayerID " << (int)remote << '\n';
      return;
    }

    // p2p 그룹에 추가
    srv->JoinP2PGroup(remote, g_groupHostID);
    cout << "PlayerID " << (int)remote << " joined group " << (int)g_groupHostID
         << '\n';

    // 플레이어 번호 부여(0부터!), 게임 관리자 클래스로 분리 필요
    int player_nth = -1;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
      if (!set_player.size()) {
        player_nth = 0;
        continue;
      }
      if (set_player.find(i) != set_player.end())
        continue;
      player_nth = i;
    }
    if (player_nth == -1)
      return;

    // 플레이어 정보 등록, 게임 관리자 클래스로 분리 필요
    set_player.insert(player_nth);
    map_HostID_player[remote] = player_nth;
    map_player_Items.insert({player_nth, set<Item>()});
    map_player_Player.insert({player_nth, Player(player_nth)});

    cout << "Player " << player_nth << "["
         << map_player_Player[player_nth].pos_x << ','
         << map_player_Player[player_nth].pos_y << "] \n";

    // 플레이어 2명 이상 시 게임 시작
    if (set_player.size() >= 2) {
      game_started = true;
      map_player_Items[0].insert(Item(0, 0));
      g_GameProxy.SendItemSet(g_groupHostID,
                              RmiContext::FastEncryptedReliableSend, 0,
                              map_player_Items[0]);
      cout << "game started!\n";
    }
  };

  // set a routine for client leave event.
  srv->OnClientLeave = [&srv](CNetClientInfo *clientInfo, ErrorInfo *errorInfo,
                              const ByteArray &comment) {
    HostID remote = clientInfo->m_HostID;

    // p2p 그룹에서 삭제
    srv->LeaveP2PGroup(remote, g_groupHostID);
    cout << "PlayerID " << (int)remote << " leaved group " << (int)g_groupHostID
         << '\n';

    // 플레이어 정보 삭제
    int player_nth = map_HostID_player[remote];
    set_player.erase(player_nth);
    map_player_Items.erase(player_nth);
    map_player_Player.erase(player_nth);
    map_HostID_player.erase(remote);

    // 플레이어 2명 미만 시 게임 종료
    if (set_player.size() < 2) {
      game_started = false;

      // 기존 플레이어 정보 초기화
      for (set<int>::const_iterator i = set_player.begin();
           i != set_player.end(); ++i) {
        map_player_Items[player_nth] = set<Item>();
        map_player_Player[player_nth] = Player();
      }
    }

    // 모든 플레이어에게 정보 전송
    for (set<int>::const_iterator i = set_player.begin(); i != set_player.end();
         ++i) {
      g_GameProxy.SendItemSet(g_groupHostID,
                              RmiContext::FastEncryptedReliableSend, *i,
                              map_player_Items[*i]);
      g_GameProxy.SendPlayer(g_groupHostID,
                             RmiContext::FastEncryptedReliableSend, *i,
                             map_player_Player[*i]);
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
