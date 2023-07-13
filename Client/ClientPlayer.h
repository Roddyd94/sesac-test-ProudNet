#pragma once
#include "../Marshal/Player.h"

class ClientPlayer : public Player {
public:
  int last_x;
  int last_y;
  ClientPlayer();
  ClientPlayer(const Player &player);
  ClientPlayer(const Player &player, int last_x, int last_y);

  ClientPlayer &operator=(Player const &player);
  ClientPlayer &operator=(Player &&player);
};