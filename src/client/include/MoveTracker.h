#ifndef PREVIOUSINFO_H
#define PREVIOUSINFO_H

#include "Coordinates.h"
#include "Player.h"
#include "Listener.h"
class MoveTracker : public Listener {
 public:
  /**
   * Constructor.
   */
  MoveTracker();
  /**
   * Sets the name of the previous player.
   * @param name string
   */
  void setPreName(string name);
  /**
   * @return name of previous player
   */
  string getName();
  /**
   * Sets the move of the previous player.
   * @param c Coordinates
   */
  void setPreMove(Coordinates c);
  /**
   * @return previous move
   */
  Coordinates getPreMove();
  /**
   * Sets boolean saying if previous player had a move.
   * @param had_move boolean
   */
  void hadMove(bool had_move);
  /**
   * @return true if previous player had a move, false otherwise
   */
  bool preHadMove();
 private:
  Coordinates previous_move_;
  string pre_name_;
  bool pre_had_move_;
};

#endif //PREVIOUSINFO_H
