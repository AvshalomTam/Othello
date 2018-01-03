#ifndef OTHELLO_GAMEROOM_H
#define OTHELLO_GAMEROOM_H
#include <string>
using namespace std;

class GameRoom {
  public:
	GameRoom(const char* name, int client_socket1);
	void setSocket2(int socket);
	const char* getGameName();
	int getClientSocket1();
	int getClientSocket2();
	void setActive();
	bool isActive();
	void closeSockets();
  private:
	const char* game_name_;
	int client_socket1_;
	int client_socket2_;
	bool active_;
};

#endif //OTHELLO_GAMEROOM_H
