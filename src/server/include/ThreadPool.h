//
// Created by avshalom on 1/22/18.
//

#ifndef THREAD_POOL_REC13_THREADPOOL_H
#define THREAD_POOL_REC13_THREADPOOL_H
#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
  public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();
  private:
    int theadsNum;
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};

#endif //THREAD_POOL_REC13_THREADPOOL_H