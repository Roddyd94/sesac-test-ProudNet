#include "ClientUI.h"

ClientUI::ClientUI() : buffer(std::cout) {}
ClientUI::ClientUI(std::ostream &buffer) : buffer(buffer) {}
ClientUI::~ClientUI() {}

ClientUI &ClientUI::get_instance() {
  static ClientUI instance;
  return instance;
}

void ClientUI::PrintGame(const ClientGameManager &game_manager) {
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{0, 0});
  for (int player_nth = 0; player_nth < MAX_PLAYERS; ++player_nth) {
    Player player = game_manager.player_array[player_nth];
    string s;
    buffer << "[" << (char)(game_manager.my_nth == player_nth ? '*' : ' ')
           << "]Player " << player_nth + 1 << ":" << player.points;

    for (int y = 0; y < TILE_ROW; ++y) {
      buffer << '\n';
      for (int x = 0; x < TILE_COL; ++x) {
        buffer << "[ " << game_manager.get_map_icon_at(player_nth, x, y)
               << " ]";
      }
    }

    buffer << '\n';
    buffer << '\n';
  }
}
void ClientUI::ResetGameScreen() { system("cls"); }