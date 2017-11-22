// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <list>
#include "../include/AIplayer.h"

AIplayer::AIplayer(const Board& board, const GameLogic& judge, cell numplayer) : Player(numplayer),
                                                                                 board_(board), judge_(judge) {}
Coordinates AIplayer::getMove() const {
  int score;
  int max;
  int minMax = this->board_.getSize() * this->board_.getSize();
  Coordinates best_move;
  list <Coordinates> computerOptions = this->judge_.getOptions(this->board_, second_player);
  best_move = *computerOptions.begin();
  for (list<Coordinates>::iterator it = computerOptions.begin(); it != computerOptions.end(); ++it) {
    Board* copyboard = this->board_.copy();
    copyboard->setCell(*it, second_player);

    max = copyboard->getScore(first_player) - copyboard->getScore(second_player);
    list <Coordinates> playerOptions = this->judge_.getOptions(*copyboard, first_player);
    for (list<Coordinates>::iterator it_pl = playerOptions.begin(); it_pl != playerOptions.end(); ++it_pl) {
      Board* tmp_board = copyboard->copy();
      tmp_board->setCell(*it_pl, first_player);
      score = tmp_board->getScore(first_player) - tmp_board->getScore(second_player);
      if (score > max) {
        max = score;
      }
      delete tmp_board;
    }

    if (max < minMax) {
      minMax = max;
      best_move = *it;
    }
    delete copyboard;
  }
  return best_move;
}