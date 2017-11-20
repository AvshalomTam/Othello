//
// Created by steve on 05/11/17.
//

#include "../include/CharBoard.h"
#include <iostream>

using namespace std;

CharBoard::CharBoard() : Board(8) {}

CharBoard::CharBoard(int size) : Board(size) {}

void CharBoard::printBoard() const {
    int size = this->getSize();
    for (int i = 1; i <= size; i++) {
        cout << " | " << i;
    }
    cout << " |" << endl;
    for (int i = 0; i < 2 + 4 * size; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < size; j++) {
            cout << " ";
            switch (this->getCell(Coordinates(i, j))) {
                case (0): cout << " ";
                    break;
                case (1): cout << "X";
                    break;
                case (2): cout << "O";
                    break;
                default: break;
            }
            cout << " |";
        }
        cout << endl;
        for (int k = 0; k < 2 + 4 * size; k++) {
            cout << "-";
        }
        cout << endl;
    }
}