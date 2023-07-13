#include "ClientGameManager.h"

ClientGameManager &ClientGameManager::get_instance() {
  static ClientGameManager instance;
  return instance;
}

char ClientGameManager::get_map_icon_at(const int player_nth, const int x,
                                        const int y) const {
  char icon_for_print = ' ';
  std::set<Item> item_set = item_set_array[player_nth];
  for (std::set<Item>::const_iterator i = item_set.begin(); i != item_set.end();
       ++i) {
    if (i->pos_x == x && i->pos_y == y)
      icon_for_print = '$';
  }
  if (player_array[player_nth].pos_x == x &&
      player_array[player_nth].pos_y == y)
    icon_for_print = '@';

  return icon_for_print;
}

ClientGameManager::ClientGameManager() {}

ClientGameManager::~ClientGameManager() {}