#include "../include/ThreadManager.h"

ThreadManager* ThreadManager::getInstance() {
    if (manager_ != NULL) {
        manager_ = new ThreadManager();
        return manager_;
    }
    else {
        return manager_;
    }
}

ThreadManager::~ThreadManager() {
    if (manager_ != NULL) {
        delete manager_;
    }
}

void ThreadManager::addThread(pthread_t p) {
    list_->push_back(p);
}

void ThreadManager::closeThreads() {
    for (vector<pthread_t >::iterator it = list_->begin(); it != list_->end(); ++it) {
        pthread_cancel(*it);
    }
}

void ThreadManager::deleteThread(pthread_t p) {
    for (vector<pthread_t>::iterator it = list_->begin(); it != list_->end(); ++it) {
        if (*it == p) {
            list_->erase(it);
        }
    }
}
