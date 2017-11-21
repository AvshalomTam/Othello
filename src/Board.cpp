// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/Board.h"
using namespace std;

Board::Board(int size) {
  this->size_ = size;
  this->cells_ = new cell*[size];
  for (int i = 0; i < size; i++) {
	this->cells_[i] = new cell[size];
	for (int j = 0; j < size; j++) {
	  this->cells_[i][j] = empty;
	}
  }
  this->cells_[size / 2 - 1][size / 2 - 1] = second_player;
  this->cells_[size / 2][size / 2] = second_player;
  this->cells_[size / 2 - 1][size / 2] = first_player;
  this->cells_[size / 2][size / 2 - 1] = first_player;
}

int Board::getSize() const {
  return this->size_;
}

cell Board::getCell(const Coordinates &c) const {
  return this->cells_[c.getX()][c.getY()];
}

void Board::setCell(Coordinates c, cell num_player) {
  this->cells_[c.getX()][c.getY()] = num_player;
}

int Board::getScore(cell num_player) {
  int score = 0;
  for (int i = 0; i < this->getSize(); i++) {
	for (int j = 0; j < this->getSize(); j++) {
	  if (this->cells_[i][j] == num_player) {
		score++;
	  }
	}
  }
  return score;
}

Board::~Board() {
  for (int i = 0; i < this->size_; i++) {
	delete[] this->cells_[i];
  }
  delete[] this->cells_;
}