// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/PreviousInfo.h"

PreviousInfo::PreviousInfo() : pre_had_move_(false) {}

void PreviousInfo::setPreName(string name) {
  this->pre_name_ = name;
}

string PreviousInfo::getName() {
  return this->pre_name_;
}

void PreviousInfo::setPreMove(Coordinates c) {
  this->previous_move_ = c;
}

Coordinates PreviousInfo::getPreMove() {
  return this->previous_move_;
}

void PreviousInfo::hadMove(bool had_move) {
  this->pre_had_move_ = had_move;
}

bool PreviousInfo::preHadMove() {
  return this->pre_had_move_;
}