//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_JOINCOMMAND_H
#define OTHELLO_JOINCOMMAND_H

#include "Command.h"
#include "GameManager.h"
class JoinCommand : public Command {
  public:
	JoinCommand(vector<GameRoom> list);
	void execute(vector<string> list);
	~JoinCommand();
  private:
	vector<GameRoom> list_;
	GameManager manager_;
};

#endif //OTHELLO_JOINCOMMAND_H
