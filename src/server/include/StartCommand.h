//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H

#include "Command.h"

class StartCommand : public Command {
	public:
		StartCommand(vector<GameRoom> list);
		void execute(vector<string> list);
		//~StartCommand();
	private:
		vector<GameRoom> list_;
};

#endif //OTHELLO_STARTCOMMAND_H
