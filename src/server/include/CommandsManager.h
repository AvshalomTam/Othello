//
// Created by steve on 12/26/17.
//

#ifndef OTHELLO_COMMANDSMANAGER_H
#define OTHELLO_COMMANDSMANAGER_H

#include <vector>
#include <map>
#include "GameRoom.h"
#include "Command.h"
class CommandsManager {
 public:
  CommandsManager(vector<GameRoom> list);
  ~CommandsManager();
  void executeCommand(string command, vector<string> list);
 private:
  map<string, Command *> commandsMap_;
};

#endif //OTHELLO_COMMANDSMANAGER_H
