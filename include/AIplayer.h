// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Coordinates.h"
#include "Board.h"
#include "GameLogic.h"
#include "Player.h"

class AIplayer : Player {
  public:
    AIplayer(const Board& board, const GameLogic& judge, cell numplayer);
    Coordinates getMove() const;
 private:
    const Board& board_;
    const GameLogic& judge_;
};

#endif //AIPLAYER_H