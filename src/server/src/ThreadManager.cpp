#include "../include/ThreadManager.h"

ThreadManager* ThreadManager::manager_ = 0;

ThreadManager* ThreadManager::getInstance() {
    if (manager_ == 0) {
        pthread_mutex_lock(&lock);
        if (manager_ == 0) {
            manager_ = new ThreadManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return manager_;
}

void ThreadManager::addThread(pthread_t p) {
    pthread_mutex_lock(&lock);
    list_->push_back(p);
    pthread_mutex_unlock(&lock);
}

void ThreadManager::closeThreads() {
    pthread_mutex_lock(&lock);
    for (vector<pthread_t >::iterator it = list_->begin(); it != list_->end(); ++it) {
        pthread_cancel(*it);
    }
    pthread_mutex_unlock(&lock);
}

void ThreadManager::deleteThread(pthread_t p) {
    pthread_mutex_lock(&lock);
    for (vector<pthread_t>::iterator it = list_->begin(); it != list_->end(); ++it) {
        if (*it == p) {
            list_->erase(it);
        }
    }
    pthread_mutex_unlock(&lock);
}
