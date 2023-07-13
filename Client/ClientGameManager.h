#pragma once
#include "../Common/Vars.h"
#include "ClientPlayer.h"
#include "stdafx.h"

class ClientGameManager {
public:
  // 내 플레이어 번호
  int my_nth;
  ClientPlayer player_array[MAX_PLAYERS];
  char map_array[MAX_PLAYERS][TILE_ROW][TILE_COL];

  static ClientGameManager &get_instance();

  ClientGameManager(ClientGameManager const &) = delete;
  ClientGameManager(ClientGameManager &&) = delete;
  ClientGameManager &operator=(ClientGameManager const &) = delete;
  ClientGameManager &operator=(ClientGameManager &&) = delete;

protected:
  ClientGameManager();
  ~ClientGameManager();
};