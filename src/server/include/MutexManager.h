#ifndef OTHELLO_MUTEXMANAGER_H
#define OTHELLO_MUTEXMANAGER_H

#include <sys/types.h>
class MutexManager {
  public:
    static MutexManager* getInstance();
    pthread_mutex_t* getGameRoomsMutex();
  private:
    MutexManager();
    static MutexManager* instance;
    pthread_mutex_t game_rooms_mutex_;
    pthread_mutex_t lock;
};

#endif //OTHELLO_MUTEXMANAGER_H
