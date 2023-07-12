#pragma once
#include "../Common/Vars.h"
#include "stdafx.h"

class PlayerInfo {
public:
  int pos_x;
  int pos_y;
  int points;
  PlayerInfo();
  void SetPosition(int x, int y);
  bool SetPosition(int8_t key);
  void AddPoint();
};

namespace Proud {
inline CMessage &operator>>(CMessage &m, PlayerInfo &info);
inline CMessage &operator<<(CMessage &m, const PlayerInfo &info);
inline void AppendTextOut(String &s, const PlayerInfo &info);
} // namespace Proud
