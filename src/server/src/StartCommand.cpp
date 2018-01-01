#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include "../include/StartCommand.h"
#include "../include/MutexManager.h"
using namespace std;

StartCommand::StartCommand(vector<GameRoom> list) : list_(list) { }

void StartCommand::execute(vector<string> list) {
    string sckt = list[0];
    int client_socket = 0;
    int i = 0;
    while (sckt[i] != '\0') {
        client_socket = 10 * client_socket + sckt[i] - '0';
        i++;
    }

    int n;
    const char* game_name = list[1].c_str();
    pthread_mutex_lock(MutexManager::getInstance()->getGameRoomsMutex());
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if (!strcmp(game_name, it->getGameName())) {
            int error = -1;
            n = write(client_socket, &error, sizeof(error));
            if (n == -1) {
                cout << "Error writing to socket 1" << endl;
            }
            pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());
            close(client_socket);
            return;
        }
    }
    pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());

    GameRoom game = GameRoom(game_name, client_socket);
    pthread_mutex_lock(MutexManager::getInstance()->getGameRoomsMutex());
    this->list_.push_back(game);
    pthread_mutex_unlock(MutexManager::getInstance()->getGameRoomsMutex());

    int wait = -5;
    n = write(client_socket, &wait, sizeof(wait));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
}
