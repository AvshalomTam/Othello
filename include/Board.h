#ifndef BOARD_H
#define BOARD_H

#include "Coordinates.h"
#ifndef CELL
#define CELL
enum cell {empty, first_player, second_player};
#endif

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
    cell getCell(const Coordinates &c) const;
    /**
     * Sets a Tile in the cell.
     * @param c coordinates of cell
     * @param num_player player's id
     */
    void setCell(Coordinates c, cell num_player);
   /**
    * Deep copy of board.
    * @param board board to be copied
    * @return copied board
    */
    virtual Board* copy() const = 0;
    /**
     * Returns score of player.
     * @param num_player number of player
     */
    int getScore(cell num_player);
    /**
     * Destructor.
     */
    ~Board();
private:
    // a 2D array representing the status of the board
    cell** cells_;
    int size_;
};

#endif //BOARD_H