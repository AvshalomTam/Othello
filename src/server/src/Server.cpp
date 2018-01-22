#include "../include/Server.h"
#include "../include/ClientHandler.h"
#include "../include/GameRoom.h"
#include "../include/ThreadManager.h"
#include "../include/CommandsManager.h"
#include "../include/RoomsManager.h"
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

struct thread_info {
    const char* filePath;
    ClientHandler handler;
};

int getPort(const char *filePath);
static void* acceptClients(void *tArgs);

Server::Server(): serverSocket(0) {}

void Server::start(const char* filePath) {
    thread_info t_args;
    t_args.handler = this->handler_;
    t_args.filePath = filePath;
	pthread_t games_thread;
	int rc = pthread_create(&games_thread, NULL, acceptClients, &t_args);
	if (rc) {
		cout << "Error: unable to create thread, " << rc << endl;
		return;
	}
	ThreadManager::getInstance()->addThread(games_thread);

	string end_server;
	do {
		cin >> end_server;
	}
	while (end_server != "exit");
}

static void* acceptClients(void *tArgs) {
	struct thread_info* t_info = (struct thread_info*) tArgs;
    const char *filePath = t_info->filePath;
    //get port from file
	int port = getPort(filePath);
	// create a socket point
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
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

	cout << "Waiting for clients..." << endl;
	while (true) {
		// Accept a new client connection
		int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
		if (clientSocket == -1) {
			throw "Error on accept";
		}
		t_info->handler.handle(clientSocket);
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
