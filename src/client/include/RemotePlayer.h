//
// Created by avshalom on 12/6/17.
//

#ifndef OTHELLO_REMOTEPLAYER_H
#define OTHELLO_REMOTEPLAYER_H
#include "Player.h"
#include "Display.h"
class RemotePlayer : public Player {
 public:

  RemotePlayer(int clientSocket, Display& gameflow, cell numplayer);
  Coordinates getMove();
  void message();
 private:
  Display& gameflow_;
  int clientSocket_;
};
#endif //OTHELLO_REMOTEPLAYER_H
