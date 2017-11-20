// EM168887
// Steve Gutfreund

#include "../include/Board.h"
using namespace std;

Board::Board(int size) {
  this->size_ = size;
  this->cells_ = new int*[size];
  for (int i = 0; i < size; i++) {
    this->cells_[i] = new int[size];
    for (int j = 0; j < size; j++) {
      this->cells_[i][j] = 0;
    }
  }
  this->cells_[size / 2 - 1][size / 2 - 1] = 2;
  this->cells_[size / 2][size / 2] = 2;
  this->cells_[size / 2 - 1][size / 2] = 1;
  this->cells_[size / 2][size / 2 - 1] = 1;
}

int Board::getSize() const {
  return this->size_;
}

int Board::getCell(const Coordinates &c) const {
  return this->cells_[c.getX()][c.getY()];
}

void Board::setCell(const Coordinates &c, int num_player) {
  this->cells_[c.getX()][c.getY()] = num_player;
}

Board::~Board() {
  for (int i = 0; i < this->size_; i++) {
    delete[] this->cells_[i];
  }
  delete[] this->cells_;
}
