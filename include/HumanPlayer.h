// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "GameLogic.h"
#include "GameFlowLook.h"
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
     * @param gameflow GameFlowLook object
     */
    HumanPlayer(cell numplayer, Board& board, GameLogic& judge, GameFlowLook& gameflow);
    /**
     * Gets coordinates in board where the player wants to put his tile
     * @return coordinates
     */
    Coordinates getMove();
 private:
    Board& board_;
    GameLogic& judge_;
    GameFlowLook& gameflow_;
};

#endif //HUMANPLAYER_H