#include "../include/CommandsManager.h"
#include "../include/StartCommand.h"
#include "../include/ListCommand.h"
#include "../include/JoinCommand.h"
#include "../include/CloseCommand.h"

CommandsManager* CommandsManager::instance = 0;
pthread_mutex_t CommandsManager::lock;

CommandsManager* CommandsManager::getInstance() {
	if (instance == 0) {
		pthread_mutex_lock(&lock);
		if (instance == 0) {
			instance = new CommandsManager();
		}
		pthread_mutex_unlock(&lock);
	}
	return instance;
}

CommandsManager::CommandsManager() {
	this->commandsMap_["start"] = new StartCommand();
	this->commandsMap_["list_games"] = new ListCommand();
	this->commandsMap_["join"] = new JoinCommand();
	this->commandsMap_["close"] = new CloseCommand();
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


