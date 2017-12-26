//
// Created by avshalom on 12/6/17.
//

#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include "../include/Display.h"
#include "../include/RemotePlayer.h"
#define NO_MOVE Coordinates(-1, -1)
#define MAX_TRANSMISSION_SIZE 10

string convertToString(char *input);

RemotePlayer::RemotePlayer(cell numplayer, int clientSocket, Display &gameflow, Listener& listener) :
    Player(numplayer), clientSocket_(clientSocket), gameflow_(gameflow), listener_(listener) {}

Coordinates RemotePlayer::getMove() {
  char input[MAX_TRANSMISSION_SIZE];
  int n = read(this->clientSocket_, input, sizeof(input));
  if (n == -1) {
    throw "Error reading from socket";
  }
  if (n == 0) {
    close(this->clientSocket_);
    throw "Server disconnected. Game finished.";
  }
  if (strcmp(input, "NoMove") == 0) {
    this->listener_.hadMove(false);
    this->hasMove(false);
    return NO_MOVE;
  }
  Coordinates move = Coordinates(convertToString(input));
  this->listener_.hadMove(true);
  this->listener_.setPreMove(move);
  this->listener_.setPreName(this->getName());
  this->hasMove(true);
  return move;
}

void RemotePlayer::message() {
  this->gameflow_.waitingForPlayer();
}

string convertToString(char *input) {
  string s;
  for (int i = 0; i < sizeof(input) && input[i] != '\0'; i++) {
    s += input[i];
  }
  return s;
}