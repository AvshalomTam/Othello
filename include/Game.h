// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

/**
 * Runs a game of Reversi.
 */
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Menu.h"
#include "GameFlowLook.h"
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
     */
    void playOneTurn();
    /**
     * Destructor.
     */
    ~Game();
private:
    Menu* menu_;
    GameFlowLook* game_flow_;
    Board* board_; // pointer, so it can point to inherited
    Player* pl1_; // pointer, so it can point to inherited
    Player* pl2_; // pointer, so it can point to inherited
    GameLogic* judge_; // pointer, so it can point to inherited
    bool frst_player_; // boolean telling who's turn it is
    Coordinates previous_move_;
};

#endif //GAME_H