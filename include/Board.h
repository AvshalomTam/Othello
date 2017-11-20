// EM168887
// Steve Gutfreund

#ifndef BOARD_H
#define BOARD_H

#include "Coordinates.h"
/**
 * Defines the gameboard in the game called 'Reversi'.
 */
class Board {
 public:
  /**
   * Constructor.
   * @param size of board (size x size)
   */
  Board(int size);
  /**
   * Prints the board.
   */
  virtual void printBoard() const = 0;
  /**
   * @return width of the board
   */
  int getSize() const;
  /**
   * @param c coordinates of a cell
   * @return the Tile
   */
  int getCell(const Coordinates &c) const;
  /**
   * Sets a Tile in the cell.
   * @param c coordinates of cell
   * @param num_player player's id
   */
  void setCell(const Coordinates &c, int num_player);
  /**
   * Destructor.
   */
  ~Board();
 private:
  // a 2D array representing the status of the board
  int** cells_;
  int size_;
};

#endif //BOARD_H