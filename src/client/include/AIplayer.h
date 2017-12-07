#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Coordinates.h"
#include "Board.h"
#include "GameLogic.h"
#include "Player.h"
#include "Display.h"
#include "Listener.h"

/**
 * Representing a pc player.
 */
class AIplayer : public Player {
  public:
    /**
     * Constructor.
     * @param board Board object
     * @param judge Gamlogic object
     * @param gameflow Display object
     * @param numplayer number of player
     */
    AIplayer(Board& board, GameLogic& judge, Display& gameflow, cell numplayer, Listener& listener);
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
    Listener& listener_;
};

#endif //AIPLAYER_H