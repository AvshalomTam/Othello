// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"

class BoardTest : public testing::Test {
 public:
  BoardTest() : board_() {}

 protected:
  CharBoard board_;
};

//test the correction of board's start values
TEST_F(BoardTest, InitializeTest) {
  EXPECT_EQ(board_.getCell(Coordinates(3, 3)), second_player) << "Cell(3,3) should equal 2"; //actually 4,4 cell
  EXPECT_EQ(board_.getCell(Coordinates(4, 4)), second_player) << "Cell(4,4) should equal 2"; //actually 5,5 cell
  EXPECT_EQ(board_.getCell(Coordinates(3, 4)), first_player) << "Cell(3,4) should equal 1"; //actually 4,5 cell
  EXPECT_EQ(board_.getCell(Coordinates(4, 3)), first_player) << "Cell(4,3) should equal 1"; //actually 5,4 cell
  for (int i = 0; i < board_.getSize(); i++) {
    for (int j = 0; j < board_.getSize(); j++) {
      if ((i != 3) && (i != 4) && (j != 3) && (j != 4)) {
        EXPECT_EQ(board_.getCell(Coordinates(i, j)), empty) << "Every other Cell should equal 0";
      }
    }
  }
}

TEST_F(BoardTest, MoveTest) {
  board_.setCell(Coordinates(5, 6), first_player);
  EXPECT_EQ(board_.getCell(Coordinates(5, 6)), first_player);
  board_.setCell(Coordinates(1, 2), second_player);
  EXPECT_EQ(board_.getCell(Coordinates(1, 2)), second_player);
}

TEST_F(BoardTest, ScoreTest) {
  board_.setCell(Coordinates(5, 6), first_player);
  EXPECT_EQ(board_.getScore(first_player), 3);
  EXPECT_EQ(board_.getScore(second_player), 2);
}

#endif //BOARDTEST_H
