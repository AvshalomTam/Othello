#include <unistd.h>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <cstring>
#include "../include/PlayerFactory.h"
#include "../include/MoveTracker.h"
#include "../include/HumanPlayer.h"
#include "../include/AIplayer.h"
#include "../include/ServerListener.h"
#include "../include/RemotePlayer.h"

PlayerFactory::PlayerFactory(Board &board, GameLogic &judge, Display &display, GameSetup &setup) {
	this->move_tracker_ = NULL;
	this->server_messenger_ = NULL;
	game_type type = setup.getGameType();
	//checks which type of game was chosen
	if (type == local) {
		this->move_tracker_ = new MoveTracker();
		this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->move_tracker_);
		this->pl2_ = new HumanPlayer(second_player, board, judge, display, *this->move_tracker_);
		this->pl1_->setName("X");
		this->pl2_->setName("O");
	}
	else if (type == computer) {
		this->move_tracker_ = new MoveTracker();
		this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->move_tracker_);
		this->pl2_ = new AIplayer(board, judge, display, second_player, *this->move_tracker_);
		this->pl1_->setName("X");
		this->pl2_->setName("O");
		display.presentPlayer(this->pl1_->getName());
	}
	else if (type == remote) {
		int number;
		int clientSocket = setup.getSocket();
		int n = read(clientSocket, &number, sizeof(number));
		if (n == -1) {
			throw "Error reading from server";
		}
		if (n == 0) {
			throw "Server disconnected.";
		}
		this->move_tracker_ = new MoveTracker();
		this->server_messenger_ = new ServerListener(this->move_tracker_, clientSocket);
		if (number == 1) {
			this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->server_messenger_);
			this->pl2_ = new RemotePlayer(second_player, clientSocket, display, *this->move_tracker_);
			this->pl1_->setName("X");
			this->pl2_->setName("O");
			display.presentPlayer(this->pl1_->getName());
		}
		else {
			this->pl1_ = new RemotePlayer(first_player, clientSocket, display, *this->move_tracker_);
			this->pl2_ = new HumanPlayer(second_player, board, judge, display, *this->server_messenger_);
			this->pl1_->setName("X");
			this->pl2_->setName("O");
			display.presentPlayer(this->pl2_->getName());
		}
	}
}

Player* PlayerFactory::getFirstPlayer() {
	return this->pl1_;
}

Player* PlayerFactory::getSecondPlayer() {
	return this->pl2_;
}

PlayerFactory::~PlayerFactory() {
	delete this->move_tracker_;
	delete this->server_messenger_;
    delete this->pl1_;
    delete this->pl2_;
}