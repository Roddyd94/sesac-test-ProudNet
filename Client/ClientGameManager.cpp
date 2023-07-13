#include "ClientGameManager.h"

ClientGameManager &ClientGameManager::get_instance() {
  static ClientGameManager instance;
  return instance;
}

ClientGameManager::ClientGameManager() {
  std::fill(&map_array[0][0][0], &map_array[MAX_PLAYERS][0][0], ' ');
}

ClientGameManager::~ClientGameManager() {}