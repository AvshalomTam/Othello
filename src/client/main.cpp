// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include "include/Game.h"

using namespace std;

int main() {
    Game game;
    game.initialize("../exe/client_settings.txt");
    game.run();
    return 0;
}