// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
public:
    /**
     * Constructor.
     * @param numplayer first_player or second_player
     */
    HumanPlayer(cell numplayer);
    /**
     * Gets coordinates in board where the player wants to put his tile
     * @return coordinates
     */
    Coordinates getMove() const;
};

#endif //HUMANPLAYER_H