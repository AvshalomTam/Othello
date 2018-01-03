#ifndef OTHELLO_ROOMSMANAGER_H
#define OTHELLO_ROOMSMANAGER_H

#include <vector>
#include "GameRoom.h"
class RoomsManager {
  public:
    static RoomsManager* getInstance();
    int addRoom(GameRoom room);
    void removeRoom(string room);
    GameRoom* addPLayer(string name);
    vector<string> getOpenRooms();
    void closeSockets();
  private:
    static RoomsManager* instance;
    static pthread_mutex_t lock;
    vector<GameRoom> list_;
};


#endif //OTHELLO_ROOMSMANAGER_H
