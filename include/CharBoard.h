// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef CHARBOARD_H
#define CHARBOARD_H
#include "Board.h"

/**
 * A board made of char.
 */
class CharBoard : public Board {
  public:
    /**
     * Default constructor. Sets the board size as 8.
     */
    CharBoard();
    /**
     * Constructor.
     * @param size board sze
     */
    CharBoard(int size);
    /**
     * Method for printing the board on the console.
     */
    void printBoard() const;
   /**
    * Deep copy of board.
    * @param board board to be copied
    * @return copied board
    */
    Board* copy() const;
};

#endif //CHARBOARD_H