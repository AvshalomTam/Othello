// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef GAMEFLOWLOOK_H
#define GAMEFLOWLOOK_H
#include <string>
#include <list>
#include "Board.h"
using namespace std;

class GameFlowLook {
 public:
  virtual void printCurrentBoard(Board &board) = 0;
  virtual void printPreviousMove(string name, string coordinate) = 0;
  virtual void printTurn(string name) = 0;
  virtual void printNoMove() = 0;
  virtual void printOptions(list<Coordinates> &options) = 0;
  virtual void printMoveRequest() = 0;
  virtual void printInputError(const char* error) = 0;
  virtual void printResult(string name = "draw") = 0;
};

#endif //GAMEFLOWLOOK_H
