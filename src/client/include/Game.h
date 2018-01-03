#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Menu2.h"
#include "Display.h"
#include "MoveTracker.h"
#include "PlayerFactory.h"
/**
 * Game of Reversi/Othello.
 */
class Game {
  public:
    /**
     * Constructor.
     */
    Game();
    /**
     * Initializes the board, the players etc.
     */
    void initialize(const char* filePath);
    /**
     * Runs the game.
     */
    void run();
    /**
     * Player plays a turn.
     * @param pl reference to player
     */
    void playOneTurn(Player &pl);
    /**
     * Destructor.
     */
    ~Game();
  private:
    PlayerFactory* factory;
    GameSetup* setup_;
    Display* game_flow_;
    Board* board_; // pointer, so it can point to inherited
    Player* pl1_; // pointer, so it can point to inherited
    Player* pl2_; // pointer, so it can point to inherited
    GameLogic* judge_; // pointer, so it can point to inherited
    bool frst_player_; // boolean telling who's turn it is
};

#endif //GAME_H