#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "../include/JoinCommand.h"
#include "../include/RoomsManager.h"
using namespace std;

JoinCommand::JoinCommand() {}

void JoinCommand::execute(vector<string> list) {
    int client_socket = atoi(list[0].c_str());

    const char *game_name = list[1].c_str();
    GameRoom *room = RoomsManager::getInstance()->addPLayer(game_name);

    if (room != 0) {
        int ok = 1;
        int n = write(client_socket, &ok, sizeof(ok));
        if (n == -1) {
            cout << "Error writing to socket 1" << endl;
            return;
        }
        room->setSocket2(client_socket);
        this->manager_.createGame(room);
        return;
    }

    int error = -1;
    int n = write(client_socket, &error, sizeof(error));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
    close(client_socket);
    return;
}