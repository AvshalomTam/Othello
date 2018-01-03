#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "pthread.h"
#include <vector>
using namespace std;

class ThreadManager {
  public:
    static ThreadManager* getInstance();
    void addThread(pthread_t p);
    void closeThreads();
    void deleteThread(pthread_t p);
  private:
    vector<pthread_t> list_;
    static ThreadManager *manager_;
    static pthread_mutex_t lock;
};

#endif //THREADMANAGER_H
