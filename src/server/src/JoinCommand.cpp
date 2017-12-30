#include <cstring>
#include <unistd.h>
#include <iostream>
#include <ostream>
#include "../include/JoinCommand.h"
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
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if ((!(strcmp(game_name, it->getGameName()))) && !it->isActive()) {
            it->setSocket2(client_socket);
            this->manager_.createGame(*it);
            return;
        }
    }

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
    //copy the list to tmp list
    for (vector<GameRoom>::iterator it = list.begin(); it != list.end(); ++it) {
        tmp.push_back(*it);
    }
    //now remove finished games from original list
    for (vector<GameRoom>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2) {
        if (it2->isFinished()) {
            list.erase(it2);
        }
    }
}

