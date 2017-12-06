//
// Created by avshalom on 12/6/17.
//

#include <unistd.h>
#include "../include/Display.h"
#include "../include/RemotePlayer.h"
RemotePlayer::RemotePlayer(cell numplayer, int clientSocket, Display &gameflow) :
    Player(numplayer), clientSocket_(clientSocket), gameflow_(gameflow) {}

Coordinates RemotePlayer::getMove() {
  char* input = NULL;
  int n = read(this->clientSocket_, input, sizeof(input));
  if (n == -1) {
    throw "Error reading from socket";
  }
  return Coordinates(input);
}
void RemotePlayer::message() {
  this->gameflow_.waitingForPlayer();
}
