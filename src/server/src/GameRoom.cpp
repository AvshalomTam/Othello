#include <unistd.h>
#include "../include/GameRoom.h"

GameRoom::GameRoom(const char* name, int client_socket1) : game_name_(name), client_socket1_(client_socket1), client_socket2_(-1) {}

const char* GameRoom::getGameName() {
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

void GameRoom::setSocket2(int socket) {
	this->client_socket2_ = socket;
}

void GameRoom::finished() {
    this->is_finished_ = true;
}

bool GameRoom::isFinished() {
    return this->is_finished_;
}
