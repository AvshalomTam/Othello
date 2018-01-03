#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/ListCommand.h"
#include "../include/RoomsManager.h"
using namespace std;

ListCommand::ListCommand() {}

void ListCommand::execute(vector<string> list) {
	int client_socket = atoi(list[0].c_str());

	vector<string> open_games = RoomsManager::getInstance()->getOpenRooms();
	int ack;
    for (vector<string>::iterator it = open_games.begin(); it != open_games.end(); ++it) {
		//write to client the names of the open games
		int n;
		string game_name = *it;
		n = write(client_socket, game_name.data(), game_name.size());
		if (n == -1) {
			cout << "Error writing to socket 1" << endl;
			close(client_socket);
			return;
		}
        n = read(client_socket, &ack, sizeof(int));
        if (n == -1) {
            cout << "Error writing to socket 1" << endl;
            close(client_socket);
            return;
        }

	}
	close(client_socket);
}
