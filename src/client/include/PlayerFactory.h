#ifndef OTHELLO_PLAYERFACTORY_H
#define OTHELLO_PLAYERFACTORY_H

#include "Board.h"
#include "GameLogic.h"
#include "Display.h"
#include "Listener.h"
#include "Player.h"
#include "Menu.h"
class PlayerFactory {
 public:
  PlayerFactory(Board &board, GameLogic &judge, Display &display, game_type type, const char* file_path);
  Player* getFirstPlayer();
  Player* getSecondPlayer();
  ~PlayerFactory();
 private:
  Player *pl1_;
  Player *pl2_;
  Listener* move_tracker_ = NULL;
  Listener* server_messenger_ = NULL;
};

#endif //OTHELLO_PLAYERFACTORY_H
