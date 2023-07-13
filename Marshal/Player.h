#pragma once
#include "../Common/Vars.h"
#include "stdafx.h"

class Player {
public:
  int nth;
  int pos_x;
  int pos_y;
  int points;
  Player();
  Player(int nth);
  Player(const Player &player);
  void SetPosition(const int x, const int y);
  bool IsMovable(int8_t key);
  void MoveToward(int8_t key);
  void AddPoint();
};

namespace Proud {
inline CMessage &operator>>(CMessage &m, Player &player);
inline CMessage &operator<<(CMessage &m, const Player &player);
inline void AppendTextOut(String &s, const Player &player);
} // namespace Proud
