#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include "../include/ClientHandler.h"
#include "../include/CommandsManager.h"
#include "../include/ThreadManager.h"
#include "../include/RoomsManager.h"
#define MAX_NAME_LENGTH 50

static void* serveClient(void *tArgs);

void ClientHandler::handle(int client_socket) {
	pthread_t serve_client;
    int rc = pthread_create(&serve_client, NULL, serveClient, &client_socket);
	if (rc) {
		cout << "Error: unable to create thread, " << rc << endl;
		return;
	}
	ThreadManager::getInstance()->addThread(serve_client);
}

ClientHandler::~ClientHandler() {
    ThreadManager::resetInstance();
	RoomsManager::resetInstance();
	CommandsManager::resetInstance();
}

static void* serveClient(void *tArgs) {
    int *c_socket = (int *) tArgs;
    int client_socket = *c_socket;
	char buffer[MAX_NAME_LENGTH]  = "\0";

	int n = read(client_socket, buffer, sizeof(buffer));
	//if client closed the connection
	if (n == 0) {
		return 0;
	}
	if (n == -1) {
		cout << "Error reading from socket" << endl;
		return 0;
	}
	bool two_words;
	char command[MAX_NAME_LENGTH];
	char argument[MAX_NAME_LENGTH];
	char* pch;
	pch = strchr(buffer, ' ');
	if (pch == NULL) {
		two_words = false;
		strcpy(command, buffer);
	}
	else {
		two_words = true;
		buffer[pch - buffer] = '\0';
		strcpy(command, buffer);
		strcpy(argument, pch + 1);
	}

	vector<string> command_arg;
	string s, tmp;
	long num = client_socket;
	while (num != 0) {
		tmp = s;
		s = num % 10 + '0';
		s.append(tmp);
		num /= 10;
	}
	command_arg.push_back(s);
	if (two_words) {
		command_arg.push_back(argument);
	}
	CommandsManager::getInstance()->executeCommand(command, command_arg);
    ThreadManager::getInstance()->deleteThread(pthread_self());
}