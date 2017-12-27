#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "GameRoom.h"
using namespace std;

class ClientHandler {
 public:
  void handle(int client_socket);
  static vector<GameRoom> getList();
  ~ClientHandler();
};

#endif //CLIENTHANDLER_H
