#include "../include/CommandsManager.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/JoinCommand.h"

CommandsManager::CommandsManager(vector<GameRoom> list) {
	this->commandsMap_["start"] = new StartCommand(list);
	this->commandsMap_["list_games"] = new ListCommand(list);
	this->commandsMap_["join"] = new JoinCommand(list);
}

void CommandsManager::executeCommand(string command, vector<string> list) {
	Command *commandObj = this->commandsMap_[command];
	commandObj->execute(list);
}

CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
	for (it = this->commandsMap_.begin(); it != this->commandsMap_.end(); it++) {
		delete it->second;
	}
}


