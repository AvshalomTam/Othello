#ifndef OTHELLO_GAMEMANAGER_H
#define OTHELLO_GAMEMANAGER_H

#include "GameRoom.h"
class GameManager {
  public:
    GameManager();
    void createGame(GameRoom *room);
};

#endif //OTHELLO_GAMEMANAGER_H
