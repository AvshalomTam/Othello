#include <cstring>
#include <unistd.h>
#include <iostream>
#include <ostream>
#include "../include/JoinCommand.h"
#include "../include/MutexManager.h"
using namespace std;
void update(vector<GameRoom> list);

JoinCommand::JoinCommand(vector<GameRoom> list) : list_(list) { }

void JoinCommand::execute(vector<string> list) {
    string sckt = list[0];
    int client_socket = 0;
    int i = 0;
    while (sckt[i] != '\0') {
        client_socket = 10 * client_socket + sckt[i] - '0';
        i++;
    }

    int n;
    const char* game_name = list[1].c_str();

    update(this->list_);
    pthread_mutex_lock(MutexManager::getInstance()->getGameRoomsMutex());
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if ((!(strcmp(game_name, it->getGameName()))) && !it->isActive()) {
            it->setSocket2(client_socket);
            this->manager_.createGame(*it);
            pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());
            return;
        }
    }
    pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());
    int error = -1;
    n = write(client_socket, &error, sizeof(error));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
    close(client_socket);
    return;
}

void update(vector<GameRoom> list) {
    vector<GameRoom> tmp;
    vector<GameRoom>::iterator it;
    //copy the list to tmp list
    pthread_mutex_lock(MutexManager::getInstance()->getGameRoomsMutex());
    for (it = list.begin(); it != list.end(); ++it) {
        tmp.push_back(*it);
    }
    //now remove finished games from original list
    for (it = tmp.begin(); it != tmp.end(); ++it) {
        if (it->isFinished()) {
            list.erase(it);
        }
    }
    pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());
}

