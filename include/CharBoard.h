//
// Created by steve on 05/11/17.
//

#ifndef CHARBOARD_H
#define CHARBOARD_H
#include "Board.h"

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
};

#endif //CHARBOARD_H