#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Menu.h"
#include "Display.h"
#include "MoveTracker.h"
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
    void initialize();
    /**
     * Runs the game.
     */
    void run();
    /**
     * Player plays a turn.
     * @param pl reference to player
     */
    void playOneTurn(Player &pl);
    int connectToServer(string filePath);
    /**
     * Destructor.
     */
    ~Game();
  private:
    Menu* menu_;
    Display* game_flow_;
    Board* board_; // pointer, so it can point to inherited
    Player* pl1_; // pointer, so it can point to inherited
    Player* pl2_; // pointer, so it can point to inherited
    GameLogic* judge_; // pointer, so it can point to inherited
    Listener* move_tracker_ = NULL;
    Listener* server_messenger_ = NULL;
    bool frst_player_; // boolean telling who's turn it is
};

#endif //GAME_H