//
// Created by avshalom on 12/6/17.
//

#ifndef OTHELLO_REMOTEPLAYER_H
#define OTHELLO_REMOTEPLAYER_H
#include "Player.h"
#include "Display.h"
#include "Listener.h"
class RemotePlayer : public Player {
 public:

  RemotePlayer(cell numplayer, int clientSocket, Display &gameflow, Listener& listener);
  Coordinates getMove();
  void message();
 private:
  Display& gameflow_;
  int clientSocket_;
  Listener& listener_;
};
#endif //OTHELLO_REMOTEPLAYER_H