// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BASICRULESTEST_H
#define BASICRULESTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"

class BasicRulesTest : public testing::Test {
 public:
  BasicRulesTest() : board_(), judge_() {}
  virtual void SetUp() {
    Coordinates move = Coordinates(2, 3);
    judge_.turnTiles(board_, move, first_player); //actually puts 1 in cell 3,4
    move = Coordinates(2, 2);
    judge_.turnTiles(board_, move, second_player); //actually puts 2 in cell 3,3
    move = Coordinates(5, 4);
    judge_.turnTiles(board_, move, first_player); //actually puts 1 in cell 6,5
    move = Coordinates(1, 3);
    judge_.turnTiles(board_, move, second_player); //actually puts 2 in cell 2,4
  }
  void setUp2() {
    Coordinates move = Coordinates(0, 3);
    judge_.turnTiles(board_, move, first_player); //actually puts 1 in cell 1,4
    move = Coordinates(0, 4);
    judge_.turnTiles(board_, move, second_player); //actually puts 2 in cell 1,5
  }
  void setUp3() {
    setUp2();
    Coordinates move = Coordinates(0, 5);
    judge_.turnTiles(board_, move, first_player); //actually puts 1 in cell 1,6
    move = Coordinates(2, 4);
    judge_.turnTiles(board_, move, second_player); //actually puts 2 in cell 3,5
  }
 protected:
  CharBoard board_;
  BasicRules judge_;
};

//test of options in one round
TEST_F(BasicRulesTest, OptionsFirstRoundTest) {
  list<Coordinates> options = judge_.getOptions(board_, first_player);
  Coordinates real[] = {Coordinates(0, 3), Coordinates(1, 1), Coordinates(1, 2), Coordinates(3, 2)};
  int i = 0;
  for (list<Coordinates>::iterator it = options.begin(); it != options.end(); ++it, i++) {
    EXPECT_EQ(it->toString(), real[i].toString());
  }
}

//test of options in second round after changing the board 4 times
TEST_F(BasicRulesTest, OptionsSecondRoundTest) {
  setUp2();
  list<Coordinates> options = judge_.getOptions(board_, first_player);
  Coordinates real[] = {Coordinates(0, 5), Coordinates(1, 1), Coordinates(2, 1)};
  int i = 0;
  for (list<Coordinates>::iterator it2 = options.begin(); it2 != options.end(); ++it2, i++) {
    EXPECT_EQ(it2->toString(), real[i].toString());
  }
}
//test of options in third round after changing the board twice
TEST_F(BasicRulesTest, OptionThirdRoundTest) {
  setUp3();
  //expected right moves
  EXPECT_TRUE(judge_.isValidChoice(board_, Coordinates(1, 1), first_player));
  EXPECT_TRUE(judge_.isValidChoice(board_, Coordinates(1, 2), first_player));
  EXPECT_TRUE(judge_.isValidChoice(board_, Coordinates(1, 4), first_player));
  EXPECT_TRUE(judge_.isValidChoice(board_, Coordinates(1, 5), first_player));
  EXPECT_TRUE(judge_.isValidChoice(board_, Coordinates(3, 1), first_player));
  //expected wrong moves
  EXPECT_FALSE(judge_.isValidChoice(board_, Coordinates(6, 1), first_player));
  EXPECT_FALSE(judge_.isValidChoice(board_, Coordinates(3, 6), first_player));
  EXPECT_FALSE(judge_.isValidChoice(board_, Coordinates(3, 2), first_player));
  EXPECT_FALSE(judge_.isValidChoice(board_, Coordinates(5, 5), first_player));
  EXPECT_FALSE(judge_.isValidChoice(board_, Coordinates(7, 7), first_player));
}

#endif //BASICRULESTEST_H
