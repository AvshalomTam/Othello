#ifndef OTHELLO_LISTCOMMAND_H
#define OTHELLO_LISTCOMMAND_H

#include "Command.h"
class ListCommand : public Command {
  public:
	void execute(vector<string> list);
};

#endif //OTHELLO_LISTCOMMAND_H
