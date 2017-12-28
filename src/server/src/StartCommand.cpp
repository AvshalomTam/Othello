#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include "../include/StartCommand.h"
using namespace std;

StartCommand::StartCommand(vector<GameRoom> list) : list(list) { }

void StartCommand::execute(vector<string> list) {
    string sckt = list[0];
    int client_socket = 0;
    int i = 0;
    while (sckt[i] != '\0') {
        client_socket = 10 * client_socket + sckt[i] - '0';
        i++;
    }

    int n;
    string game_name = list[1];
    for (vector<GameRoom>::iterator it = this->list.begin(); it != this->list.end(); ++it) {
        if (!strcmp(game_name, it->getGameName())) {
            int error = -1;
            n = write(client_socket, &error, sizeof(error));
            if (n == -1) {
                cout << "Error writing to socket 1" << endl;
                return;
            }
            close(client_socket);
        }
    }
    int wait = -5;
    n = write(client_socket, &wait, sizeof(wait));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
}
