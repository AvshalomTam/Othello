#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/AIplayer.h"
#include "../include/ConsoleMenu.h"
#include "../include/ConsoleDisplay.h"
#include "../include/RemotePlayer.h"

Game::Game() : frst_player_(true) {}

void Game::initialize() {
  this->menu_ = new ConsoleMenu();
  this->game_flow_ = new ConsoleDisplay();
  this->board_ = new CharBoard();
  this->judge_ = new BasicRules();
  this->menu_->printMenu();
  this->game_info_ = new PreviousInfo();
  if (this->menu_->getGameType() == local) {
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_);
    this->pl2_ = new HumanPlayer(second_player, *this->board_, *this->judge_, *this->game_flow_);
  }
  else if (this->menu_->getGameType() == computer) {
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_);
    this->pl2_ = new AIplayer(*this->board_, *this->judge_, *this->game_flow_, second_player);
  }
  else if (this->menu_->getGameType() == remote) {
    const char* serverIP = getServerIP();
    int serverPort = this->getServerPort();
    int clientSocket = getClientSocket(serverIP, serverPort);
    char* number;
    int n = read(clientSocket, number, sizeof(number));
    if (n == -1) {
      throw "Error reading from server";
    }
    if (strcmp(number, "1") == 0) {
      this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_);
      this->pl2_ = new RemotePlayer(clientSocket, *this->game_flow_, second_player);
    }
    else {
      this->pl2_ = new HumanPlayer(second_player, *this->board_, *this->judge_, *this->game_flow_);
      this->pl1_ = new RemotePlayer(clientSocket, *this->game_flow_, first_player);
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
  while ((this->pl1_->played() || this->pl2_->played()) && (!this->judge_->boardIsFull(*this->board_)));

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
  //prints previous player move
  if (this->game_info_->preHadMove()) {
    this->game_flow_->printPreviousMove(this->game_info_->getName(), this->game_info_->getPreMove().toString());
  }
  //prints whose turn it is
  this->game_flow_->printTurn(pl.getName());

  //if the player has no moves
  if (!this->judge_->hasOptions(*this->board_, pl.getId())) {
    this->game_info_->hadMove(false);
    pl.hasMove(false);
    this->game_flow_->printNoMove();
    return;
  }

  pl.message();
  Coordinates input = pl.getMove();
  this->game_info_->hadMove(true);
  pl.hasMove(true);
  this->judge_->turnTiles(*this->board_, input, pl.getId());
  this->game_info_->setPreMove(input.move(Coordinates(1, 1)));
  this->game_info_->setPreName(pl.getName());
}

int Game::getServerPort() {
  return 6000;
}

const char* Game::getServerIP() {
  return "127.0.0.1";
}

int Game::getClientSocket(const char* serverIP, int serverPort) {
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
}

