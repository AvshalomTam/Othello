#include "../include/CommandsManager.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/JoinCommand.h"
#include "../include/PlayCommand.h"
#include "../include/CloseCommand.h"

CommandsManager::CommandsManager() {
  this->commandsMap_["start"] = new StartCommand();
  this->commandsMap_["list_games"] = new ListCommand();
  this->commandsMap_["join"] = new JoinCommand();
  this->commandsMap_["play"] = new PlayCommand();
  this->commandsMap_["close"] = new CloseCommand();
}

void CommandsManager::executeCommand(string command, vector<GameRoom> list) {
  Command *commandObj = this->commandsMap_[command];
  commandObj->execute(list);
}

CommandsManager::~CommandsManager() {
  map<string, Command *>::iterator it;
  for (it = this->commandsMap_.begin(); it != this->commandsMap_.end(); it++) {
    delete it->second;
  }
}


