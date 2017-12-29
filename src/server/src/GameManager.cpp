#include "../include/GameManager.h"
#include "pthread.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int middleMan(int clientSocketRead, int clientSocketWrite);
static void handleClients(int clientSocket1, int clientSocket2);
#define MAX_TRANSMISSION_SIZE 10
struct sockets {
    int client_socket1;
    int client_socket2;
};

GameManager::GameManager() {}

void GameManager::createGame(int client_socket1, int client_socket2) {
    sockets tArgs;
    tArgs.client_socket1 = client_socket1;
    tArgs.client_socket2 = client_socket2;
    pthread_t games_thread;
    int rc = pthread_create(&games_thread, NULL, connectGamers, &tArgs);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        return;
    }
}

static void* connectGamers(void *tArgs) {
    struct sockets *args = (struct sockets *) tArgs;

    handleClients(args->client_socket1, args->client_socket2);

    // Close communication with the client
    close(args->client_socket1);
    close(args->client_socket2);
}

static void handleClients(int clientSocket1, int clientSocket2) {
    int n;
    int num;

    num = 1;
    n = write(clientSocket1, &num, sizeof(num));
    if (n == -1) {
        cout << "Error writing to socket 1" << endl;
        return;
    }
    num = 2;
    n = write(clientSocket2, &num, sizeof(num));
    if (n == -1) {
        cout << "Error writing to socket 2" << endl;
        return;
    }

    bool first_socket = true;
    int m;
    do {
        if (first_socket) {
            m = middleMan(clientSocket1, clientSocket2);
        }
        else {
            m = middleMan(clientSocket2, clientSocket1);
        }
        first_socket = !first_socket;
    } while (m != 0);
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


