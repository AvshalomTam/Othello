// EM168887
// Steve Gutfreund

#ifndef BASICRULES_H
#define BASICRULES_H

#include "Board.h"
#include "Coordinates.h"
#include "GameLogic.h"
#include <list>

/**
 * Contains all the logic and the rules of the game.
 */
class BasicRules : public GameLogic {
public:
    /**
     * Creates a list of all the options the player has according to the player's number.
     * @param num_player player's number
     * @return list of coordinates
     */
    list <Coordinates> getOptions(Board &board, int num_player) const;
    /**
     * Check if the choice c num_player has chosen, is valid.
     * @param board game board
     * @param c coordinates
     * @param num_player number of player
     * @return true if valid, false otherwise
     */
    bool isValidChoice(Board &board, Coordinates c, int num_player) const;
    /**
     * Turns the tiles according the rules after placing num_player on c.
     * @param c coordinates
     * @param num_player the player who wants to turn some tiles
     */
    void turnTiles(Board &board, const Coordinates &c, int num_player);
    /**
     * Checks who's the winner of the game.
     * @return number of player who won and 0 for a draw
     */
    int checkWinner(Board &board) const;
    /**
     * @return true if the board is full, false otherwise
     */
    bool boardIsFull(Board &board) const;
};

#endif //BASICRULES_H