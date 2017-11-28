// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef CONSOLEGAMEFLOW_H
#define CONSOLEGAMEFLOW_H

#include "GameFlowLook.h"
class ConsoleGameFlow : public GameFlowLook{
 public:
  void printCurrentBoard(Board &board);
  void printPreviousMove(string name, string coordinate);
  void printTurn(string name);
  void printNoMove();
  void printOptions(list<Coordinates> &options);
  void printMoveRequest();
  void printInputError(const char* error);
  void printResult(string name = "draw");
};

#endif //CONSOLEGAMEFLOW_H
