#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include "../include/ClientHandler.h"
#include "../include/GameRoom.h"
#include "../include/CommandsManager.h"
#include "../include/ThreadManager.h"

struct client_thread {
    int client_socket;
    pthread_t serve_client;
};

vector<GameRoom> list;
CommandsManager manager = CommandsManager(list);

static void* serveClient(void *tArgs);

void ClientHandler::handle(int client_socket) {
	ThreadManager *t_manager = ThreadManager::getInstance();
    pthread_t serve_client;
    client_thread tArgs;
    tArgs.client_socket = client_socket;
    tArgs.serve_client = serve_client;
	int rc = pthread_create(&serve_client, NULL, serveClient, &tArgs);
	if (rc) {
		cout << "Error: unable to create thread, " << rc << endl;
		return;
	}
    t_manager->addThread(serve_client);
}

static void* serveClient(void *tArgs) {
    client_thread *targs = (client_thread *) tArgs;
    int client_socket = targs->client_socket;
	char buffer[50];
	for (int i = 0; i < 50; i++) {
		buffer[i] = '\0';
	}
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
	char command[50];
	char argument[50];
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
	manager.executeCommand(command, command_arg);
    ThreadManager *manager = ThreadManager::getInstance();
    manager->deleteThread(targs->serve_client);
}

ClientHandler::~ClientHandler() {
	for (vector<GameRoom>::iterator it = list.begin(); it != list.end(); ++it) {
		it->closeSockets();
	}
}
