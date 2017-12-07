//
// Created by steve on 12/6/17.
//

#include <unistd.h>
#include <iostream>
#include <cstring>
#include "../include/Listener.h"
#include "../include/ServerListener.h"

string intStringConvert(int num);

ServerListener::ServerListener(Listener *listener, int clientSocket) : listener_(listener), client_socket_(clientSocket) {}

void ServerListener::setPreName(string name) {
  this->listener_->setPreName(name);
}

string ServerListener::getName() {
  return this->listener_->getName();
}

void ServerListener::setPreMove(Coordinates c) {
  this->listener_->setPreMove(c);
  string coordinates = intStringConvert(c.getX()) + "," + intStringConvert(c.getY()) +'\0';
  int n = write(this->client_socket_, coordinates.data(), coordinates.size());
  if (n == -1) {
    throw "Error writing to socket";
  }
}

Coordinates ServerListener::getPreMove() {
  return this->listener_->getPreMove();
}

void ServerListener::hadMove(bool had_move) {
  this->listener_->hadMove(had_move);
}

bool ServerListener::preHadMove() {
  return this->listener_->preHadMove();
}

string intStringConvert(int num) {
  bool negative = false;
  if (num == 0) {
    return "0";
  }
  if (num < 0) {
    negative = true;
    num *= -1;
  }
  string s, tmp;
  while (num != 0) {
    tmp = s;
    s = num % 10 + '0';
    s.append(tmp);
    num /= 10;
  }
  if (negative) {
    return "-" + s;
  }
  return s;
}
