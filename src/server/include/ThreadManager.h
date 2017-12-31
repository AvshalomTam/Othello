#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "pthread.h"
#include <vector>
using namespace std;

class ThreadManager {
  public:
    static ThreadManager* getInstance();
    static void addThread(pthread_t p);
    static void closeThreads();
    static void deleteThread(pthread_t p);
    ~ThreadManager();
  private:
    ThreadManager();
    static vector<pthread_t> *list_;
    static ThreadManager *manager_ = NULL;
};

#endif //THREADMANAGER_H
