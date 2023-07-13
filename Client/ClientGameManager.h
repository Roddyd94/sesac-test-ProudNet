#pragma once
#include "../Common/Vars.h"
#include "../Marshal/Item.h"
#include "../Marshal/Player.h"
#include "stdafx.h"

class ClientGameManager {
public:
  // 내 플레이어 번호
  int my_nth;
  Player player_array[MAX_PLAYERS];
  std::set<Item> item_set_array[MAX_PLAYERS];

  static ClientGameManager &get_instance();

  char get_map_icon_at(const int player_nth, const int x, const int y) const;
  ClientGameManager(ClientGameManager const &) = delete;
  ClientGameManager(ClientGameManager &&) = delete;
  ClientGameManager &operator=(ClientGameManager const &) = delete;
  ClientGameManager &operator=(ClientGameManager &&) = delete;

protected:
  ClientGameManager();
  ~ClientGameManager();
};