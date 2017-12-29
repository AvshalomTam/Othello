//
// Created by steve on 12/26/17.
//

#include <cstring>
#include <unistd.h>
#include <iostream>
#include "../include/JoinCommand.h"
using namespace std;

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
    string game_name = list[1];

    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if (!strcmp(game_name, it->getGameName()) && !it->isActive()) {
            it->setSocket2(client_socket);
            this->manager_.createGame(it->getClientSocket1(), client_socket);
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

