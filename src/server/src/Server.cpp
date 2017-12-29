#include "../include/Server.h"
#include "../include/ClientHandler.h"
#include "../include/GameRoom.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <pthread.h>
#include <vector>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
enum {wait = -5};

int getPort(const char *filePath);
static void* acceptClients(void *tArgs);

struct connection_info {
	struct sockaddr_in clientAddress;
	socklen_t clientAddressLen;
	int serverSocket;
	ClientHandler handler;
};

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

	connection_info info;
	info.clientAddress = clientAddress;
	info.clientAddressLen = clientAddressLen;
	info.serverSocket = serverSocket;

	ClientHandler handler;
	info.handler = handler;
	pthread_t games_thread;
	int rc = pthread_create(&games_thread, NULL, acceptClients, &info);
	if (rc) {
		cout << "Error: unable to create thread, " << rc << endl;
		return;
	}

	string end_server;
	do {
		cin >> end_server;
	}
	while (end_server != "exit");
	close(serverSocket);
}

static void* acceptClients(void *tArgs) {
	struct connection_info *args = (struct connection_info *) tArgs;
	cout << "Waiting for clients..." << endl;
	while (true) {
		// Accept a new client connection
		int clientSocket =
				accept(args->serverSocket, (struct sockaddr *) &(args->clientAddress), &(args->clientAddressLen));
		if (clientSocket == -1)
			throw "Error on accept";
		cout << "Client accepted" << endl;
		args->handler.handle(clientSocket);
	}
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
