#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "../include/RoomsManager.h"
using namespace std;

RoomsManager* RoomsManager::instance = 0;
pthread_mutex_t RoomsManager::lock;

RoomsManager* RoomsManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new RoomsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

int RoomsManager::addRoom(GameRoom &room) {
    pthread_mutex_lock(&lock);
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if (room.getGameName() == it->getGameName()) {
            pthread_mutex_unlock(&lock);
            return 0;
        }
    }
    this->list_.push_back(room);
    pthread_mutex_unlock(&lock);
    return 1;
}

void RoomsManager::removeRoom(string room) {
    vector<GameRoom>::iterator it;
    //copy the list to Menu list
    pthread_mutex_lock(&lock);
    for (it = this->list_.begin(); it != this->list_.end(); ++it) {
        if (room == it->getGameName()) {
            break;
        }
    }
    this->list_.erase(it);
    pthread_mutex_unlock(&lock);
}

GameRoom* RoomsManager::addPLayer(string name) {
    pthread_mutex_lock(&lock);
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if ((name == it->getGameName()) && !it->isActive()) {
            it->setActive();
            pthread_mutex_unlock(&lock);
            return &(*it);
        }
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

vector<string> RoomsManager::getOpenRooms() {
    vector<string> open;
    pthread_mutex_lock(&lock);
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        if (!it->isActive()) {
            open.push_back(it->getGameName());
        }
    }
    pthread_mutex_unlock(&lock);
    return open;
}

RoomsManager::~RoomsManager() {
    if (this->list_.empty()) {
        return;
    }
    for (vector<GameRoom>::iterator it = this->list_.begin(); it != this->list_.end(); ++it) {
        it->closeSockets();
    }
}

void RoomsManager::resetInstance() {
    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}
