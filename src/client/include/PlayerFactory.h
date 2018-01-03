#ifndef OTHELLO_PLAYERFACTORY_H
#define OTHELLO_PLAYERFACTORY_H

#include "Board.h"
#include "GameLogic.h"
#include "Display.h"
#include "Listener.h"
#include "Player.h"
#include "Menu2.h"
#include "GameSetup.h"
/**
 * This class creates objects of players according the game type.
 */
class PlayerFactory {
 public:
  /**
   * Constructor, creates 2 player objects.
   * @param board Board object
   * @param judge GameLogic object
   * @param display Display object (responsible for input and output)
   * @param type game type (enum), local, computer or remote
   * @param file_path path to file containing the server information
   */
  PlayerFactory(Board &board, GameLogic &judge, Display &display, GameSetup &setup);
  /**
   * @return the first player
   */
  Player* getFirstPlayer();
  /**
   * @return the second player
   */
  Player* getSecondPlayer();
  /**
   * Destructor.
   */
  ~PlayerFactory();
 private:
  Player *pl1_;
  Player *pl2_;
  Listener* move_tracker_;
  Listener* server_messenger_;
};

#endif //OTHELLO_PLAYERFACTORY_H
