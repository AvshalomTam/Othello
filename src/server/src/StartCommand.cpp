#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../include/StartCommand.h"
#include "../include/RoomsManager.h"
using namespace std;

void StartCommand::execute(vector<string> list) {
    int client_socket = atoi(list[0].c_str());

    const char *game_name = list[1].c_str();
    GameRoom game = GameRoom(game_name, client_socket);
    int n = RoomsManager::getInstance()->addRoom(game);

    if (n == 0) {
        int error = -1;
        n = write(client_socket, &error, sizeof(int));
        if (n == -1) {
            cout << "Error writing to socket 1" << endl;
        }
        close(client_socket);
        return;
    }

    int wait = 1;
    n = write(client_socket, &wait, sizeof(int));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
}