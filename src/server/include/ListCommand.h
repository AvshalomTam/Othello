//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_LISTCOMMAND_H
#define OTHELLO_LISTCOMMAND_H

#include "Command.h"
class ListCommand : public Command {
	public:
		ListCommand(vector<GameRoom> list);
		void execute(vector<string> list);
		~ListCommand();
	private:
		vector<GameRoom> list_;
};

#endif //OTHELLO_LISTCOMMAND_H
