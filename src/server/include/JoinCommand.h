#ifndef OTHELLO_JOINCOMMAND_H
#define OTHELLO_JOINCOMMAND_H

#include "Command.h"
#include "GameManager.h"
class JoinCommand : public Command {
  public:
	JoinCommand();
	void execute(vector<string> list);
	//~JoinCommand();
  private:
	GameManager manager_;
};

#endif //OTHELLO_JOINCOMMAND_H
