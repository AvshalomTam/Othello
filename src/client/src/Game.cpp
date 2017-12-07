#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/AIplayer.h"
#include "../include/ConsoleMenu.h"
#include "../include/ConsoleDisplay.h"
#include "../include/RemotePlayer.h"
#include "../include/ServerListener.h"
#define NO_MOVE Coordinates(-1, -1)

Game::Game() : frst_player_(true) {}

void Game::initialize() {
  this->menu_ = new ConsoleMenu();
  this->game_flow_ = new ConsoleDisplay();
  this->board_ = new CharBoard(3);
  this->judge_ = new BasicRules();
  this->game_info_ = new MoveTracker();
  //print the menu
  this->menu_->printMenu();

  //check which type of game to initialize and play
  if (this->menu_->getGameType() == local) {
    this->move_tracker_ = new MoveTracker();
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_, *this->move_tracker_);
    this->pl2_ = new HumanPlayer(second_player, *this->board_, *this->judge_, *this->game_flow_, *this->move_tracker_);
  }
  else if (this->menu_->getGameType() == computer) {
    this->move_tracker_ = new MoveTracker();
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_, *this->move_tracker_);
    this->pl2_ = new AIplayer(*this->board_, *this->judge_, *this->game_flow_, second_player, *this->move_tracker_);
  }
  else if (this->menu_->getGameType() == remote) {
    int clientSocket = connectToServer("filePath");
    int number;
    int n = read(clientSocket, &number, sizeof(number));
    if (n == -1) {
      throw "Error reading from server";
    }
    this->move_tracker_ = new MoveTracker();
    this->server_messenger_ = new ServerListener(this->move_tracker_, clientSocket);
    if (number == 1) {
      this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_, *this->server_messenger_);
      this->pl2_ = new RemotePlayer(second_player, clientSocket, *this->game_flow_, *this->move_tracker_);
    }
    else {
      this->pl1_ = new RemotePlayer(first_player, clientSocket, *this->game_flow_, *this->move_tracker_);
      this->pl2_ = new HumanPlayer(second_player, *this->board_, *this->judge_, *this->game_flow_, *this->server_messenger_);
    }
  }
  this->pl1_->setName("X");
  this->pl2_->setName("O");
}

void Game::run() {
  do {
    if (this->frst_player_) {
      this->playOneTurn(*this->pl1_);
    }
    else {
      this->playOneTurn(*this->pl2_);
    }
    this->frst_player_ = !this->frst_player_;
  }
  while ((this->pl1_->played() || this->pl2_->played()));

  this->board_->printBoard();
  //printing the game results
  int winner = this->judge_->checkWinner(*this->board_);
  if (winner == 0) {
    this->game_flow_->printResult();
  }
  else {
    if (winner == first_player) {
      this->game_flow_->printResult(this->pl1_->getName());
    }
    else {
      this->game_flow_->printResult(this->pl2_->getName());
    }
  }
}

void Game::playOneTurn(Player &pl) {
  this->game_flow_->printCurrentBoard(*this->board_);

  pl.message();
  //get move from current player
  Coordinates input = pl.getMove();
  if (!NO_MOVE.isEqual(input)) {
    this->judge_->turnTiles(*this->board_, input, pl.getId());
  }
}

int Game::connectToServer(string filePath) {
  const char *serverIP = "127.0.0.1";
  int serverPort = 5050;
  // Create a socket point
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    throw "Error opening socket";
  }
  // Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(serverIP, &address)) {
    throw "Can't parse IP address";
  }
  // Get a hostent structure for the given host address
  struct hostent *server;
  server = gethostbyaddr((const void *)&address, sizeof(address), AF_INET);
  if (server == NULL) {
    throw "Host is unreachable";
  }
  // Create a structure for the server address
  struct sockaddr_in serverAddress;
  bzero((char *)&address, sizeof(address));

  serverAddress.sin_family = AF_INET;
  memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  // htons converts values between host and network byte orders
  serverAddress.sin_port = htons(serverPort);

  // Establish a connection with the TCP server
  if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error connecting to server";
  }
  return clientSocket;
}

Game::~Game() {
  delete this->menu_;
  delete this->game_flow_;
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
  delete this->game_info_;
  if (this->move_tracker_ != NULL)
    delete this->move_tracker_;
  if (this->server_messenger_ != NULL)
    delete this->server_messenger_;
}

