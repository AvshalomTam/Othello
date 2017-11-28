// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <list>
#include "Coordinates.h"
#include "Board.h"

/**
 * Holds all the logic of the game.
 */
class GameLogic {
public:
    /**
     * Creates a list of all the options the player has according to the player's number.
     * @param num_player player's number
     * @return list of coordinates
     */
    virtual list <Coordinates> getOptions(const Board &board, cell num_player) const = 0;
    /**
     * Check if the choice c num_player has chosen, is valid.
     * @param board game board
     * @param c coordinates
     * @param num_player number of player
     * @return true if valid, false otherwise
     */
    virtual bool isValidChoice(Board &board, Coordinates c, cell num_player) const = 0;
    /**
     * Turns the tiles according the rules after placing num_player on c.
     * @param c coordinates
     * @param num_player the player who wants to turn some tiles
     */
    virtual void turnTiles(Board &board, Coordinates &c, cell num_player) = 0;
    /**
     * Checks who's the winner of the game.
     * @return number of player who won and 0 for a draw
     */
    virtual int checkWinner(Board &board) const = 0;
    /**
     * @return true if the board is full, false otherwise
     */
    virtual bool boardIsFull(Board &board) const = 0;
};

#endif //GAMELOGIC_H