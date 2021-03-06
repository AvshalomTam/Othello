#include <list>
#include "../include/AIplayer.h"
#define NO_MOVE Coordinates(-1, -1)

AIplayer::AIplayer(Board& board, GameLogic& judge, Display& gameflow, cell numplayer, Listener& listener) :
    Player(numplayer), board_(board), judge_(judge), gameflow_(gameflow), listener_(listener) {}
Coordinates AIplayer::getMove() {
  if (!this->judge_.hasOptions(this->board_, this->getId())) {
    this->listener_.hadMove(false);
    this->hasMove(false);
    return NO_MOVE;
  }
  int score;
  signed int max;
  int minMax = this->board_.getSize() * this->board_.getSize();
  Coordinates best_move;
  list <Coordinates> computerOptions = this->judge_.getOptions(this->board_, second_player);
  best_move = *computerOptions.begin();
  for (list<Coordinates>::iterator it = computerOptions.begin(); it != computerOptions.end(); ++it) {
    Board* copyboard = this->board_.copy();
    this->judge_.turnTiles(*copyboard, *it, second_player);

    max = -1 * this->board_.getSize() * this->board_.getSize();
    list <Coordinates> playerOptions = this->judge_.getOptions(*copyboard, first_player);
    for (list<Coordinates>::iterator it_pl = playerOptions.begin(); it_pl != playerOptions.end(); ++it_pl) {
      Board* tmp_board = copyboard->copy();
      this->judge_.turnTiles(*tmp_board, *it_pl, first_player);
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
  this->listener_.hadMove(true);
  this->listener_.setPreMove(best_move);
  this->listener_.setPreName(this->getName());
  this->hasMove(true);
  return best_move;
}

void AIplayer::message() {
  if (!this->judge_.hasOptions(this->board_, this->getId())) {
    this->gameflow_.printNoMove();
    return;
  }
  this->gameflow_.pcCalculating();
}