#ifndef OTHELLO_GAMEROOM_H
#define OTHELLO_GAMEROOM_H
#include <string>
using namespace std;

class GameRoom {
 public:
  GameRoom(string name, int client_socket1);
  string getGameName();
    int getClientSocket1();
    int getClientSocket2();
  bool isActive();
  void closeSockets();
 private:
  string game_name_;
  int client_socket1_;
  int client_socket2_;

};

#endif //OTHELLO_GAMEROOM_H
