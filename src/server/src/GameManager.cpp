#include "../include/GameManager.h"
#include "pthread.h"
#include "../include/ThreadManager.h"
#include "../include/CommandsManager.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int middleMan(int clientSocketRead, int clientSocketWrite);
#define MAX_TRANSMISSION_SIZE 10

GameManager::GameManager() {}
static void* connectGamers(void *tArgs);

void GameManager::createGame(GameRoom *room) {
    pthread_t game_thread;

    int rc = pthread_create(&game_thread, NULL, connectGamers, room);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        return;
    }
    ThreadManager::getInstance()->addThread(game_thread);
}

static void* connectGamers(void *tArgs) {
    GameRoom *room = (GameRoom *) tArgs;
    int client_socket1 = room->getClientSocket1();
    int client_socket2 = room->getClientSocket2();

    int n;
    int num;

    num = 1;
    n = write(client_socket1, &num, sizeof(num));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return NULL;
    }
    num = 2;
    n = write(client_socket2, &num, sizeof(num));
    if (n == -1) {
        cout << "Error writing to socket 2" << endl;
        return NULL;
    }

    bool first_socket = true;
    int m;
    do {
        if (first_socket) {
            m = middleMan(client_socket1, client_socket2);
        }
        else {
            m = middleMan(client_socket2, client_socket1);
        }
        first_socket = !first_socket;
    } while (m != 0);


    // Close communication with the client
    room->closeSockets();
    vector<string> name;
    name.push_back(room->getGameName());
    CommandsManager::getInstance()->executeCommand("close", name);
    ThreadManager::getInstance()->deleteThread(pthread_self());
}

int middleMan(int clientSocketRead, int clientSocketWrite) {
    char coordinates[MAX_TRANSMISSION_SIZE] = "\0";
    int n = read(clientSocketRead, coordinates, sizeof(coordinates));
    //if client closed the connection
    if (n == 0) {
        return 0;
    }
    if (n == -1) {
        cout << "Error reading from socket" << endl;
        return 0;
    }

    n = write(clientSocketWrite, coordinates, sizeof(coordinates));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return 0;
    }

    return 1;
}


