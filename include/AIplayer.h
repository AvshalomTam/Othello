// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Coordinates.h"
#include "Board.h"
#include "GameLogic.h"
#include "Player.h"
#include "GameFlowLook.h"

/**
 * Representing a pc player.
 */
class AIplayer : public Player {
  public:
    AIplayer(const Board& board, const GameLogic& judge, GameFlowLook& gameflow, cell numplayer);
    Coordinates getMove();
 private:
    const Board& board_;
    const GameLogic& judge_;
    GameFlowLook& gameflow_;
};

#endif //AIPLAYER_H