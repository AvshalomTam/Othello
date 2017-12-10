//
// Created by avshalom on 12/6/17.
//

#ifndef OTHELLO_LISTENER_H
#define OTHELLO_LISTENER_H
#include "Coordinates.h"
/**
 * This class represents a listener to the game.
 * He gathers info for 'some reason' (depends on the actual implementation).
 */
class Listener {
 public:
  /**
   * Sets the name of the previous player.
   * @param name string
   */
  virtual void setPreName(string name) = 0;
  /**
   * @return name of previous player
   */
  virtual string getName() = 0;
  /**
   * Sets the move of the previous player.
   * @param c Coordinates
   */
  virtual void setPreMove(Coordinates c) = 0;
  /**
   * @return previous move
   */
  virtual Coordinates getPreMove() = 0;
  /**
   * Sets boolean saying if previous player had a move.
   * @param had_move boolean
   */
  virtual void hadMove(bool had_move) = 0;
  /**
   * @return true if previous player had a move, false otherwise
   */
  virtual bool preHadMove() = 0;
 private:
  Coordinates previous_move_;
  string pre_name_;
  bool pre_had_move_;
};

#endif //OTHELLO_LISTENER_H
