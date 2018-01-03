#ifndef OTHELLO_GAMEROOM_H
#define OTHELLO_GAMEROOM_H
#include <string>
using namespace std;

class GameRoom {
  public:
	GameRoom(string name, int client_socket1);
	void setSocket1(int socket);
	void setSocket2(int socket);
	string getGameName();
	int getClientSocket1();
	int getClientSocket2();
	void setActive();
	bool isActive();
	void closeSockets();
  private:
	string game_name_;
	int client_socket1_;
	int client_socket2_;
	bool active_;
};

#endif //OTHELLO_GAMEROOM_H
