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
    static CommandsManager* getInstance();
    void executeCommand(string command, vector<string> list);
    ~CommandsManager();
 private:
    CommandsManager();
    static CommandsManager* instance;
    map<string, Command *> commandsMap_;
    static pthread_mutex_t lock;
};

#endif //OTHELLO_COMMANDSMANAGER_H
