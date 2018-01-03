#ifndef OTHELLO_GAMESETUP_H
#define OTHELLO_GAMESETUP_H
#include "Menu.h"
#include "Display.h"
#include <unistd.h>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <cstring>

enum game_type {local, computer, remote};

class GameSetup {
  public:
    GameSetup(const char* filePath);
    void setup();
    void setMainMenu();
    void setRemoteMenu();
    int remoteSetup();
    game_type getGameType();
    void setServerAddress();
    int createConnection();
    int getSocket();
    ~GameSetup();
    int listGames();
    int joinGame();
    int startGame();
  private:
    game_type type_;
    int socket_;
    const char* filepath_;
    struct sockaddr_in serverAddress;
    Menu* main_menu_;
    Menu* remote_menu_;
    Display* display;
};

#endif //OTHELLO_GAMESETUP_H
