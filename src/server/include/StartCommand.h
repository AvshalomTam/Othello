//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H

#include "Command.h"

class StartCommand : public Command {
	public:
		StartCommand();
		void execute(vector<string> list);
		//~StartCommand();
};

#endif //OTHELLO_STARTCOMMAND_H
