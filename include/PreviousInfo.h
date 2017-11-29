// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef PREVIOUSINFO_H
#define PREVIOUSINFO_H

#include "Coordinates.h"
#include "Player.h"
class PreviousInfo {
 public:
  PreviousInfo();
  void setPreName(string name);
  string getName();
  void setPreMove(Coordinates c);
  Coordinates getPreMove();
  void hadMove(bool had_move);
  bool preHadMove();
 private:
  Coordinates previous_move_;
  string pre_name_;
  bool pre_had_move_;
};

#endif //PREVIOUSINFO_H
