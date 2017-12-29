#ifndef OTHELLO_GAMEMANAGER_H
#define OTHELLO_GAMEMANAGER_H

class GameManager {
  public:
    GameManager();
    void createGame(int client_socket1, int client_socket2);
};

#endif //OTHELLO_GAMEMANAGER_H
