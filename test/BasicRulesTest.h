// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BASICRULESTEST_H
#define BASICRULESTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
/**
 * Testing BasicRules.
 */
class BasicRulesTest : public testing::Test {
 public:
  BasicRulesTest() : board_(), judge_() {}
  /**
 * Setting Up the board and making 4 moves.
 */
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
  /**
  * making another 2 moves in the game by turning tiles in the board.
  */
  void setUp2() {
    Coordinates move = Coordinates(0, 3);
    judge_.turnTiles(board_, move, first_player); //actually puts 1 in cell 1,4
    move = Coordinates(0, 4);
    judge_.turnTiles(board_, move, second_player); //actually puts 2 in cell 1,5
  }
  /**
  * making another 2 moves in the game by turning tiles in the board.
  */
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

//tests of getOptions function (of first player) after making several moves in the game
TEST_F(BasicRulesTest, getOptionsTest) {
  //after making 4 moves in the game
  list<Coordinates> options = judge_.getOptions(board_, first_player);
  Coordinates real[] = {Coordinates(0, 3), Coordinates(1, 1), Coordinates(1, 2), Coordinates(3, 2)};
  int i = 0;
  for (list<Coordinates>::iterator it = options.begin(); it != options.end(); ++it, i++) {
    EXPECT_EQ(it->toString(), real[i].toString());
  }
  //after making 6 moves in the game
  setUp2();
  options = judge_.getOptions(board_, first_player);
  Coordinates real2[] = {Coordinates(0, 5), Coordinates(1, 1), Coordinates(2, 1)};
  i = 0;
  for (list<Coordinates>::iterator it2 = options.begin(); it2 != options.end(); ++it2, i++) {
    EXPECT_EQ(it2->toString(), real2[i].toString());
  }
}

//test of isValidChoice function (of first player) after making 8 moves in the game
TEST_F(BasicRulesTest, isValidChoiceTest) {
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
//test of checkWinner function.
TEST_F(BasicRulesTest, checkWinnerTest) {
  EXPECT_EQ(judge_.checkWinner(board_), empty);
  setUp2();
  EXPECT_EQ(judge_.checkWinner(board_), first_player);
  setUp3();
  EXPECT_EQ(judge_.checkWinner(board_), first_player);
}

//test of boardIsFull function.
TEST_F(BasicRulesTest, boardIsFullTest) {
  //fill the board with X
  for (int i = 0; i < board_.getSize(); i++) {
    for (int j = 0; j < board_.getSize(); j++) {
        board_.setCell(Coordinates(i,j), first_player);
    }
  }
  EXPECT_TRUE(judge_.boardIsFull(board_));
}
#endif //BASICRULESTEST_H
