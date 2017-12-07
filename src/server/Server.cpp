//
// Created by steve on 12/5/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define MAX_TRANSMISSION_SIZE 10

Server::Server(int port): port(port), serverSocket(0) {}

void Server::start() {
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
    cout << "Waiting for clients connections..." << endl;

    // Accept a new client connection
    int clientSocket1 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (clientSocket1 == -1)
      throw "Error on accept 1";
    cout << "Client 1 accepted on socket : " << clientSocket1 << endl;

    int clientSocket2 = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (clientSocket2 == -1)
      throw "Error on accept 2";
    cout << "Client 2 accepted on socket : " << clientSocket2 << endl;

    this->handleClients(clientSocket1, clientSocket2);

    // Close communication with the client
    close(clientSocket1);
    close(clientSocket2);
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

int Server::middleMan(int clientSocketRead, int clientSocketWrite) {
  char coordinates[MAX_TRANSMISSION_SIZE];
  int n = read(clientSocketRead, coordinates, sizeof(coordinates));
  if (n == -1) {
    cout << "Error reading from socket" << endl;
    return 0;
  }
  if (strcmp(coordinates, "End") == 0) {
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