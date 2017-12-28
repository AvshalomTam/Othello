#ifndef OTHELLO_COMMAND_H
#define OTHELLO_COMMAND_H
#include <vector>
#include "GameRoom.h"
using namespace std;

class Command {
	public:
		virtual void execute(vector<string> list) = 0;
		virtual ~Command() {}
};

#endif //OTHELLO_COMMAND_H
