#include <iostream>
#include "../include/HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(cell numplayer, Board& board, GameLogic& judge, Display& gameflow) :
    Player(numplayer),  board_(board), judge_(judge), gameflow_(gameflow) {}

Coordinates HumanPlayer::getMove() {
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
      this->message();
      continue;
    }
  }
  return input;
}

void HumanPlayer::message() {
  list <Coordinates> options = this->judge_.getOptions(this->board_, this->getId());
  //printing the player's options
  this->gameflow_.printOptions(options);

  this->gameflow_.printMoveRequest();

}