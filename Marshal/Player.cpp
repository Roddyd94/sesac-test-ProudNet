#include "Player.h"

Player::Player() : Player(-1) {}

Player::Player(int nth) : nth(nth) {
  pos_x = MAP_CENTER_X;
  pos_y = MAP_CENTER_Y;
  points = 0;
}

Player::Player(const Player &player) {
  nth = player.nth;
  points = player.points;
  pos_x = player.pos_x;
  pos_y = player.pos_y;
}

void Player::SetPosition(int x, int y) {
  pos_x = x;
  pos_y = y;
}

bool Player::IsMovable(int8_t key) {
  switch (key) {
  case 'W':
  case 'w':
    if (pos_y + 1 == TILE_ROW)
      return false;
    return true;
  case 'S':
  case 's':
    if (pos_y == 0)
      return false;
    return true;
  case 'A':
  case 'a':
    if (pos_x == 0)
      return false;
    return true;
  case 'D':
  case 'd':
    if (pos_x + 1 == TILE_COL)
      return false;
    return true;
  default:
    return false;
  }
  return false;
}

void Player::MoveToward(int8_t key) {
  switch (key) {
  case 'W':
  case 'w':
    if (pos_y + 1 != TILE_ROW)
      pos_y++;
    break;
  case 'S':
  case 's':
    if (pos_y != 0)
      pos_y--;
    break;
  case 'A':
  case 'a':
    if (pos_x != 0)
      pos_x--;
    break;
  case 'D':
  case 'd':
    if (pos_x + 1 != TILE_COL)
      pos_x++;
    break;
  }
}

void Player::AddPoint() { points++; }

namespace Proud {
inline CMessage &operator>>(CMessage &m, Player &player) {
  m >> player.nth >> player.points >> player.pos_x >> player.pos_y;
  return m;
}

inline CMessage &operator<<(CMessage &m, const Player &player) {
  m << player.nth << player.points << player.pos_x << player.pos_y;
  return m;
}

inline void AppendTextOut(String &s, const Player &player) {
  String f;
  f.Format(L"Player %d{points: %d, x: %d, y: %d}", player.nth, player.points,
           player.pos_x, player.pos_y);
  s += f;
}
} // namespace Proud
