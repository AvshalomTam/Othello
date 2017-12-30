#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include "../include/ListCommand.h"
using namespace std;

ListCommand::ListCommand(vector<GameRoom> list) : list_(list) { }

void ListCommand::execute(vector<string> list) {
	string sckt = list[0];
	int client_socket = 0;
	int i = 0;
	while (sckt[i] != '\0') {
		client_socket = 10 * client_socket + sckt[i] - '0';
		i++;
	}

	for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
		if (!it->isActive()) {
			//write to client the names of the open games
			int n;
			string game_name = it->getGameName();
			n = write(client_socket, &game_name, sizeof(game_name));
			if (n == -1) {
                cout << "Error writing to socket 1" << endl;
				return;
			}
		}
	}
	close(client_socket);
}
