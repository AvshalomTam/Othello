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
  string command;
  string argument;
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



  /*
  char command[50];
  char argument[50];
  bool space = false;
  bool two_words = false;
  for (int i = 0; i < 50; i++) {
    if (buffer[i] != ' ' && !space) {
      command[i] = buffer[i];
    }
    if (buffer[i] == ' ' && !space) {
      space = true;
      command[i] = '\0';
    }
    if (buffer[i] == '$' && !space) {
      two_words = false;
      command[i] = '\0';
      break;
    }
    if (buffer[i] != ' ' && space) {
      two_words = true;
      argument[i - strlen(command)] = buffer[i];
    }
    if (buffer[i] == '$' && space) {
      argument[i - strlen(command)] = '\0';
      break;
    }
  }*/


}

static vector<GameRoom> ClientHandler::getList() {
  return list;
}