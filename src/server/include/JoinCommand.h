//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_JOINCOMMAND_H
#define OTHELLO_JOINCOMMAND_H

#include "Command.h"
class JoinCommand : public Command {
 public:
  JoinCommand(vector<GameRoom> list);
  void execute(vector<string> list);
  ~JoinCommand();
};

#endif //OTHELLO_JOINCOMMAND_H
