// EM168887
// Steve Gutfreund

#include <iostream>
#include "../include/BasicRules.h"

enum {empty, first_player, second_player};

/**
 * Checks if cell c is a valid option for num_player.
 * @param board board game
 * @param c coordinates
 * @param num_player number of player
 * @return true if valid, false otherwise
 */
bool isValidOption(Board &board, const Coordinates &c, int num_player);
/**
 * Checks if from c there is a valid path for num_player in direction vector.
 * @param board
 * @param c board game
 * @param num_player number of player
 * @param vector coordinates of direction
 * @return true if there a valid cell, false otherwise
 */
bool isValidPath(Board &board, const Coordinates &c, int num_player, const Coordinates &vector);

list<Coordinates> BasicRules::getOptions(Board &board, int num_player) const {
    //iterating over the whole board in order to check every cell
    list <Coordinates> options;
    int current_cell;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            current_cell = board.getCell(Coordinates(i, j));
            if (current_cell == empty) {
                if (isValidOption(board, Coordinates(i, j), num_player)) {
                    options.push_back(Coordinates(i, j));
                }
            }
        }
    }
    return options;
}

bool isValidOption(Board &board, const Coordinates &c, int num_player) {
    //array containing all the 8 directions
    Coordinates vector[8] = {Coordinates(0, -1), Coordinates(0, 1), Coordinates(1, -1), Coordinates(1, 0),
                             Coordinates(1, 1), Coordinates(-1, -1), Coordinates(-1, 0), Coordinates(-1, 1)};
    for (int i = 0; i < 8; i++) {
        if (isValidPath(board, c, num_player, vector[i])) {
            return true;
        }
    }
    return false;
}

bool isValidPath(Board &board, const Coordinates &c,int num_player, const Coordinates &vector) {
    bool other_sign = false;
    Coordinates tmp = c.move(vector);
    while ((tmp.getX() < board.getSize() && (tmp.getX() >= 0)
            && (tmp.getY() < board.getSize()) && tmp.getY() >= 0)) {
        if (board.getCell(tmp) == num_player) {
            return other_sign;
        }
        else {
            if (board.getCell(tmp) == empty) {
                return false;
            }
            other_sign = true;
            tmp = tmp.move(vector);
        }
    }
    return false;
}

void BasicRules::turnTiles(Board &board, const Coordinates &c, int num_player) {
    if (!isValidOption(board, c, num_player)) {
        return;
    }

    board.setCell(c, num_player);
    Coordinates vector[8] = {Coordinates(0, -1), Coordinates(0, 1), Coordinates(1, -1), Coordinates(1, 0),
                             Coordinates(1, 1), Coordinates(-1, -1), Coordinates(-1, 0), Coordinates(-1, 1)};
    for (int i = 0; i < 8; i++) {
        if (isValidPath(board, c, num_player, vector[i])) {
            Coordinates tmp = c.move(vector[i]);
            while (board.getCell(tmp) != num_player) {
                board.setCell(tmp, num_player);
                tmp = tmp.move(vector[i]);
            }
        }
    }
}

int BasicRules::checkWinner(Board &board) const {
    int one_count = 0;
    int two_count = 0;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getCell(Coordinates(i, j)) == first_player) {
                one_count++;
            }
            else {
                if (board.getCell(Coordinates(i, j)) == second_player) {
                    two_count++;
                }
            }
        }
    }
    if (one_count == two_count) {
        return 0;
    }
    if (one_count > two_count) {
        return first_player;
    }
    else {
        return second_player;
    }
}

bool BasicRules::boardIsFull(Board &board) const {
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getCell(Coordinates(i, j)) == empty) {
                return false;
            }
        }
    }
    return true;
}

bool BasicRules::isValidChoice(Board &board, Coordinates c, int num_player) const {
    if (c.getX() < 0 || c.getX() >= board.getSize() || c.getY() < 0 || c.getY() >= board.getSize()) {
        throw "Out of the game borders!";
    }
    return board.getCell(c) == 0 && isValidOption(board, c, num_player);
}