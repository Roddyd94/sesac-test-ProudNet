#include "ClientPlayer.h"

ClientPlayer::ClientPlayer() : Player() {
  last_x = MAP_CENTER_X;
  last_y = MAP_CENTER_Y;
}
ClientPlayer::ClientPlayer(const Player &player) : Player(player) {}
ClientPlayer::ClientPlayer(const Player &player, int last_x, int last_y)
    : Player(player), last_x(last_x), last_y(last_y) {}

ClientPlayer &ClientPlayer::operator=(Player const &player) {
  this->points = player.points;
  this->pos_x = player.pos_x;
  this->pos_y = player.pos_y;
  return *this;
}
ClientPlayer &ClientPlayer::operator=(Player &&player) {
  this->points = player.points;
  this->pos_x = player.pos_x;
  this->pos_y = player.pos_y;
  return *this;
}