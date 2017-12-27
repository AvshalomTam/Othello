#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include "../include/ClientHandler.h"
#include "../include/GameRoom.h"

vector<GameRoom> list;

void ClientHandler::handle(int client_socket) {
  pthread_t serve_client;
  int rc = pthread_create(&serve_client, NULL, serveClient, &client_socket);
  if (rc) {
    cout << "Error: unable to create thread, " << rc << endl;
    return;
  }
}

static void* serveClient(void *tArgs) {
  long client_socket = (long) tArgs;
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
}

static vector<GameRoom> ClientHandler::getList() {
  return list;
}