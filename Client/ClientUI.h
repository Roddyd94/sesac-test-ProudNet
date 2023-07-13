#pragma once
#include "../Common/Vars.h"
#include "ClientGameManager.h"
#include "stdafx.h"

using std::string;

class ClientUI {
private:
  std::ostream &buffer;

public:
  static ClientUI &get_instance();

  ClientUI(ClientUI const &) = delete;
  ClientUI(ClientUI &&) = delete;
  ClientUI &operator=(ClientUI const &) = delete;
  ClientUI &operator=(ClientUI &&) = delete;

  void PrintGame(const ClientGameManager &game_manager);
  void ResetGameScreen();

protected:
  ClientUI();
  ClientUI(std::ostream &buffer);
  ~ClientUI();
};
