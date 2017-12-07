#include "../include/MoveTracker.h"

MoveTracker::MoveTracker() : pre_had_move_(false) {}

void MoveTracker::setPreName(string name) {
  this->pre_name_ = name;
}

string MoveTracker::getName() {
  return this->pre_name_;
}

void MoveTracker::setPreMove(Coordinates c) {
  this->previous_move_ = c;
}

Coordinates MoveTracker::getPreMove() {
  return this->previous_move_;
}

void MoveTracker::hadMove(bool had_move) {
  this->pre_had_move_ = had_move;
}

bool MoveTracker::preHadMove() {
  return this->pre_had_move_;
}