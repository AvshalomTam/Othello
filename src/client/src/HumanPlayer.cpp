#include <iostream>
#include "../include/HumanPlayer.h"
#define NO_MOVE Coordinates(-1, -1)
#define END Coordinates(-2, -2)
using namespace std;

HumanPlayer::HumanPlayer(cell numplayer, Board& board, GameLogic& judge, Display& gameflow, Listener& listener) :
    Player(numplayer),  board_(board), judge_(judge), gameflow_(gameflow), listener_(listener) {}

Coordinates HumanPlayer::getMove() {
  if (!this->listener_.preHadMove() && !this->judge_.hasOptions(this->board_, this->getId())) {
    this->listener_.hadMove(false);
    this->listener_.setPreMove(END);
    this->listener_.setPreName(this->getName());
    this->hasMove(false);
    return NO_MOVE;
  }
  if (!this->judge_.hasOptions(this->board_, this->getId())) {
    this->listener_.hadMove(false);
    this->listener_.setPreMove(NO_MOVE);
    this->listener_.setPreName(this->getName());
    this->hasMove(false);
    return NO_MOVE;
  }

  Coordinates input;
  this->hasMove(true);

  while (true) {
    try {
      string s = this->gameflow_.input();
      input = Coordinates(s).move(Coordinates(-1, -1));
      //checking if player's choice is one of the options
      if (this->judge_.isValidChoice(this->board_, input, this->getId())) {
        break;
      }
      else {
        throw "That's none of your choices!";
      }
    } catch (const char* error) {
      this->gameflow_.printInputError(error);
      this->gameflow_.printMoveRequest();
      continue;
    }
  }
  this->listener_.hadMove(true);
  this->listener_.setPreMove(input);
  this->listener_.setPreName(this->getName());
  this->hasMove(true);
  return input;
}

void HumanPlayer::message() {
  //prints previous player move
  if (this->listener_.preHadMove()) {
    this->gameflow_.printPreviousMove(this->listener_.getName(), (this->listener_.getPreMove().move(Coordinates(1, 1)).toString()));
  }

  //prints whose turn it is
  this->gameflow_.printTurn(this->getName());

  if (!this->judge_.hasOptions(this->board_, this->getId())) {
    this->gameflow_.printNoMove();
    return;
  }
  list <Coordinates> options = this->judge_.getOptions(this->board_, this->getId());
  //printing the player's options
  this->gameflow_.printOptions(options);

  this->gameflow_.printMoveRequest();

}