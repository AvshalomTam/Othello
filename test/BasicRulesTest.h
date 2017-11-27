// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BASICRULESTEST_H
#define BASICRULESTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"

class BasicRulesTest: public testing::Test {
 public:
  BasicRulesTest(): b1(), judge() {}

  virtual void SetUp() {
    Coordinates move = Coordinates(2, 3);
    judge.turnTiles(b1, move, first_player); //actually puts in cell 3,4
    move = Coordinates(2, 2);
    judge.turnTiles(b1, move, second_player); //actually puts in cell 3,3
    move = Coordinates(5, 4);
    judge.turnTiles(b1, move, first_player); //actually puts in cell 6,5
    move = Coordinates(1, 3);
    judge.turnTiles(b1, move, second_player); //actually puts in cell 2,4
  }

 protected:
  CharBoard b1;
  BasicRules judge;
};

TEST_F(BasicRulesTest, OptionsTest) {
  list<Coordinates> options = judge.getOptions(b1, first_player);
  Coordinates real[] = {Coordinates(0, 3), Coordinates(1, 1), Coordinates(1, 2), Coordinates(3, 2)};
  int i = 0;
  for (list<Coordinates>::iterator it = options.begin(); it != options.end(); ++it, i++) {
    EXPECT_EQ(it->toString(), real[i].toString());
  }
}
#endif //BASICRULESTEST_H