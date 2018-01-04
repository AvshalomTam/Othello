// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include <cstdlib>
#include "include/Game.h"

using namespace std;

int main() {
    Game game;
    try {
        game.initialize("../exe/client_settings.txt");
        game.run();
    } catch (const char* e) {
        exit(0);
    }
    return 0;
}