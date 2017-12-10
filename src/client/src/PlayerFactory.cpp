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
enum {wait = -5};
int connectToServer(const char* filePath);

PlayerFactory::PlayerFactory(Board &board, GameLogic &judge, Display &display, game_type type, const char *file_path) {
  //checks which type of game was chosen
  if (type == local) {
    this->move_tracker_ = new MoveTracker();
    this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->move_tracker_);
    this->pl2_ = new HumanPlayer(second_player, board, judge, display, *this->move_tracker_);
  }
  else if (type == computer) {
    this->move_tracker_ = new MoveTracker();
    this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->move_tracker_);
    this->pl2_ = new AIplayer(board, judge, display, second_player, *this->move_tracker_);
  }
  else if (type == remote) {
    int clientSocket = connectToServer(file_path);
    int number;
    int n = read(clientSocket, &number, sizeof(number));
    if (n == -1) {
      throw "Error reading from server";
    }
    if (number == wait) {
      display.waitForOtherPlayerConnect();
      n = read(clientSocket, &number, sizeof(number));
      if (n == -1) {
        throw "Error reading from server";
      }
    }
    this->move_tracker_ = new MoveTracker();
    this->server_messenger_ = new ServerListener(this->move_tracker_, clientSocket);
    if (number == 1) {
      this->pl1_ = new HumanPlayer(first_player, board, judge, display, *this->server_messenger_);
      this->pl2_ = new RemotePlayer(second_player, clientSocket, display, *this->move_tracker_);
    }
    else {
      this->pl1_ = new RemotePlayer(first_player, clientSocket, display, *this->move_tracker_);
      this->pl2_ = new HumanPlayer(second_player, board, judge, display, *this->server_messenger_);
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
}

int connectToServer(const char* filePath) {
  //allocating places
  string serverIP;
  const char* serverIP_c;
  int serverPort;
  //open file
  ifstream inFile;
  inFile.open(filePath);
  if (inFile.is_open()) {
    //reading first line
    inFile >> serverPort;
    //reading second line
    inFile >> serverIP;
  }
  else {
    throw "Error opening file";
  }
  //close the file
  inFile.close();
  serverIP_c = serverIP.c_str();
  // Create a socket point
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    throw "Error opening socket";
  }
  // Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(serverIP_c, &address)) {
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
