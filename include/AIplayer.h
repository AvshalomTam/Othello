#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Coordinates.h"
#include "Board.h"
#include "GameLogic.h"
#include "Player.h"
#include "Display.h"

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
    AIplayer(const Board& board, const GameLogic& judge, Display& gameflow, cell numplayer);
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
    const Board& board_;
    const GameLogic& judge_;
    Display& gameflow_;
};

#endif //AIPLAYER_H