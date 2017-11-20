// EM168887
// Steve Gutfreund

#include <iostream>
#include "../include/HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(int numplayer) : Player(numplayer) {}

Coordinates HumanPlayer::getMove() const {
    string s;
    cin >> s;
    cin.get();
    return Coordinates(s);
}