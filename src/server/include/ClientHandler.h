#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "GameRoom.h"
#include <vector>
using namespace std;

class ClientHandler {
  public:
	void handle(int client_socket);
	~ClientHandler();
};

#endif //CLIENTHANDLER_H
