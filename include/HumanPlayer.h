#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "GameLogic.h"
#include "Display.h"
#include "PreviousInfo.h"

/**
 * Representing a human player.
 */
class HumanPlayer : public Player {
public:
    /**
     * Constructor.
     * @param numplayer first_player or second_player
     * @param board Board object
     * @param judge Gamelogic object
     * @param gameflow Display object
     */
    HumanPlayer(cell numplayer, Board& board, GameLogic& judge, Display& gameflow);
    /**
     * Gets coordinates in board where the player wants to put his tile
     * @return coordinates
     */
    Coordinates getMove();
    /**
     * Prints an appropieate message.
     */
   void message();
 private:
    Board& board_;
    GameLogic& judge_;
    Display& gameflow_;
};

#endif //HUMANPLAYER_H