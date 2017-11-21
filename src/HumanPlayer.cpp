// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include "../include/HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(cell numplayer) : Player(numplayer) {}

Coordinates HumanPlayer::getMove() const {
    string s;
    cin >> s;
    cin.get();
    return Coordinates(s);
}