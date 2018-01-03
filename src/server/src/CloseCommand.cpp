#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include "../include/CloseCommand.h"
#include "../include/RoomsManager.h"
using namespace std;

void CloseCommand::execute(vector<string> list) {
    string game_name = list[0];

    RoomsManager::getInstance()->removeRoom(game_name);
}
