#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H

#include "Command.h"
class CloseCommand : public Command {
  public:
    CloseCommand();
    void execute(vector<string> list);
};

#endif //CLOSECOMMAND_H