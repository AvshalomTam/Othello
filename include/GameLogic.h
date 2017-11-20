//
// Created by steve on 11/9/17.
//

#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <list>
#include "Coordinates.h"
#include "Board.h"
class GameLogic {
public:
    /**
     * Creates a list of all the options the player has according to the player's number.
     * @param num_player player's number
     * @return list of coordinates
     */
    virtual list <Coordinates> getOptions(Board &board, int num_player) const = 0;
    /**
     * Check if the choice c num_player has chosen, is valid.
     * @param board game board
     * @param c coordinates
     * @param num_player number of player
     * @return true if valid, false otherwise
     */
    virtual bool isValidChoice(Board &board, Coordinates c, int num_player) const = 0;
    /**
     * Turns the tiles according the rules after placing num_player on c.
     * @param c coordinates
     * @param num_player the player who wants to turn some tiles
     */
    virtual void turnTiles(Board &board, const Coordinates &c, int num_player) = 0;
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