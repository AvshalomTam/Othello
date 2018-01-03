#ifndef OTHELLO_JOINCOMMAND_H
#define OTHELLO_JOINCOMMAND_H

#include "Command.h"
#include "GameManager.h"
class JoinCommand : public Command {
  public:
	void execute(vector<string> list);
  private:
	GameManager manager_;
};

#endif //OTHELLO_JOINCOMMAND_H
