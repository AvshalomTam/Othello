#ifndef OTHELLO_LISTCOMMAND_H
#define OTHELLO_LISTCOMMAND_H

#include "Command.h"
class ListCommand : public Command {
  public:
	ListCommand();
	void execute(vector<string> list);
	//~ListCommand();
};

#endif //OTHELLO_LISTCOMMAND_H
