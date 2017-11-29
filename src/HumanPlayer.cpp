// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include "../include/HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(cell numplayer, Board& board, GameLogic& judge, GameFlowLook& gameflow, PreviousInfo& game_info) :
    Player(numplayer),  board_(board), judge_(judge), gameflow_(gameflow), game_info_(game_info) {}

Coordinates HumanPlayer::getMove() {
  Coordinates input;
  this->hasMove(true);

  list <Coordinates> options = this->judge_.getOptions(this->board_, this->getId());
  while (true) {
    //printing the player's options
    this->gameflow_.printOptions(options);

    this->gameflow_.printMoveRequest();
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
      continue;
    }
  }
  return input;
}