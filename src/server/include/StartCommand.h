#ifndef OTHELLO_STARTCOMMAND_H
#define OTHELLO_STARTCOMMAND_H

#include "Command.h"

class StartCommand : public Command {
	public:
		void execute(vector<string> list);
};

#endif //OTHELLO_STARTCOMMAND_H
