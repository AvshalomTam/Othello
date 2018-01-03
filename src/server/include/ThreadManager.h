#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "pthread.h"
#include <vector>
using namespace std;

class ThreadManager {
  public:
    static ThreadManager* getInstance();
    static void resetInstance();
    void addThread(pthread_t p);
    void deleteThread(pthread_t p);
    ~ThreadManager();
  private:
    vector<pthread_t> list_;
    static ThreadManager *instance;
    static pthread_mutex_t lock;
};

#endif //THREADMANAGER_H
