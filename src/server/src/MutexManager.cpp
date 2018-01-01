#include <pthread.h>
#include "../include/MutexManager.h"

MutexManager* MutexManager::instance = 0;

MutexManager *MutexManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new MutexManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

pthread_mutex_t *MutexManager::getGameRoomsMutex() {
    return &(this->game_rooms_mutex_);
}

