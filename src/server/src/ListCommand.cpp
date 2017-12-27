//
// Created by steve on 12/26/17.
//
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include "../include/ListCommand.h"
using namespace std;
ListCommand::ListCommand(vector<GameRoom> list) : list(list) {
}

void ListCommand::execute(vector<string> list) {
    for (vector<GameRoom>::iterator it = this->list.begin(); it != this->list.end(); ++it) {
        if (!it->isActive()) {
            //write to client the gamename
            int n;
            string gamename = it->getGameName();
            //n = write(???, &gamename, sizeof(gamename));
            if (n == -1) {
                cout << "Error writing to socket 1" << endl;
                return;
            }
        }
    }
}
