#include "../include/Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define MAX_TRANSMISSION_SIZE 10
enum {wait = -5};

int middleMan(int clientSocketRead, int clientSocketWrite);
int getPort(const char *filePath);

Server::Server(): serverSocket(0) {}

void Server::start(const char* filePath) {
  //get port from file
  this->port = getPort(filePath);
  // create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *)&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }

  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);

  // Define the client socket's structures
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen;

  while (true) {
    cout << "Waiting for 2 clients..." << endl;

    // Accept a new client connection
    int clientSocket1 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (clientSocket1 == -1)
      throw "Error on accept 1";
    cout << "Client 1 accepted on socket : " << clientSocket1 << endl;

    int num = wait;
    int n = write(clientSocket1, &num, sizeof(num));
    if (n == -1)
      throw "Error communicating";

    int clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (clientSocket2 == -1)
      throw "Error on accept 2";
    cout << "Client 2 accepted on socket : " << clientSocket2 << endl;

    this->handleClients(clientSocket1, clientSocket2);

    // Close communication with the client
    close(clientSocket1);
    close(clientSocket2);
    cout << "Clients disconnected" << endl << endl;
  }
}

// Handle requests from a specific client
void Server::handleClients(int clientSocket1, int clientSocket2) {
  int n;
  int num;

  num = 1;
  n = write(clientSocket1, &num, sizeof(num));
  if (n == -1) {
    cout << "Error writing to socket 1" << endl;
    return;
  }
  num = 2;
  n = write(clientSocket2, &num, sizeof(num));
  if (n == -1) {
    cout << "Error writing to socket 2" << endl;
    return;
  }

  bool first_socket = true;
  int m;
  do {
    if (first_socket) {
      m = middleMan(clientSocket1, clientSocket2);
    }
    else {
      m = middleMan(clientSocket2, clientSocket1);
    }
    first_socket = !first_socket;
  } while (m != 0);
}

int middleMan(int clientSocketRead, int clientSocketWrite) {
  char coordinates[MAX_TRANSMISSION_SIZE] = "\0";
  int n = read(clientSocketRead, coordinates, sizeof(coordinates));
  //if client closed the connection
  if (n == 0) {
    return 0;
  }
  if (n == -1) {
    cout << "Error reading from socket" << endl;
    return 0;
  }

  n = write(clientSocketWrite, coordinates, sizeof(coordinates));
  if (n == -1) {
    cout << "Error writing to socket" << endl;
    return 0;
  }

  return 1;
}

void Server::stop() {
  close(serverSocket);
}

int getPort(const char *filePath) {
  int port;
  ifstream inFile;
  inFile.open(filePath);
  if (inFile.is_open()) {
    //reading first line
    inFile >> port;
  }
  else {
    throw "Error opening file";
  }
  //close the file
  inFile.close();
  return port;
}
