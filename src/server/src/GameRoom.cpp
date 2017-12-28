#include <unistd.h>
#include "../include/GameRoom.h"

GameRoom::GameRoom(string name, int client_socket1) : game_name_(name), client_socket1_(client_socket1), client_socket2_(-1) {}

string GameRoom::getGameName() {
	return this->game_name_;
}

bool GameRoom::isActive() {
	return this->client_socket2_!= -1;
}

void GameRoom::closeSockets() {
	close(this->client_socket1_);
	if (client_socket2_ != -1) {
		close(client_socket2_);
	}
}

int GameRoom::getClientSocket1() {
	return this->client_socket1_;
}
int GameRoom::getClientSocket2() {
	return this->client_socket2_;
}
