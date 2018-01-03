#include <iostream>
#include "../include/ThreadManager.h"

ThreadManager* ThreadManager::instance = 0;
pthread_mutex_t ThreadManager::lock;

ThreadManager* ThreadManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new ThreadManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

void ThreadManager::addThread(pthread_t p) {
    pthread_mutex_lock(&lock);
    list_.push_back(p);
    pthread_mutex_unlock(&lock);
}

void ThreadManager::deleteThread(pthread_t p) {
    vector<pthread_t >::iterator it;
    pthread_mutex_lock(&lock);
    for (it = list_.begin(); it != list_.end(); ++it) {
        if (*it == p) {
            break;
        }
    }
    list_.erase(it);
    pthread_mutex_unlock(&lock);
}

void ThreadManager::resetInstance() {
    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}

ThreadManager::~ThreadManager() {
    pthread_mutex_lock(&lock);
    for (vector<pthread_t >::iterator it = list_.begin(); it != list_.end(); ++it) {
        pthread_cancel(*it);
    }
    pthread_mutex_unlock(&lock);
}
