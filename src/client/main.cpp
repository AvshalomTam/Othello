// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include "include/Game.h"

using namespace std;

int main() {
    try {
        Game game;
        game.initialize("../exe/client_settings.txt");
        game.run();
    } catch (const char* e) {
        //just ignore and finish the game
    }
    return 0;
}