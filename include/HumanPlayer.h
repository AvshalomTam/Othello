// EM168887
// Steve Gutfreund

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
public:
    /**
     * Constructor.
     * @param numplayer 1 or 2
     */
    HumanPlayer(int numplayer);
    /**
     * Gets coordinates in board where the player wants to put his tile
     * @return coordinates
     */
    Coordinates getMove() const;
};

#endif //HUMANPLAYER_H