// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/CharBoard.h"
#include <iostream>

using namespace std;

CharBoard::CharBoard() : Board() {}

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
                case (empty): cout << " ";
                    break;
                case (first_player): cout << "X";
                    break;
                case (second_player): cout << "O";
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

Board* CharBoard::copy() const {
    Board* copy = new CharBoard(this->getSize());

    for (int i = 0; i < this->getSize(); i++) {
        for (int j = 0; j < this->getSize(); j++) {
            copy->setCell(Coordinates(i, j), this->getCell(Coordinates(i, j)));
        }
    }

    return copy;
}