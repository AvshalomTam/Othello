#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "GameRoom.h"
#include "ThreadPool.h"
#include <vector>

using namespace std;
#define THREADS_NUM 5

class ClientHandler {
  public:
	ClientHandler();
	void handle(int client_socket);
	~ClientHandler();
  private:
	ThreadPool pool;
};

#endif //CLIENTHANDLER_H
