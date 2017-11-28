// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"

/**
 * Testing Board.
 */
class BoardTest: public testing::Test {
 public:
  BoardTest(): board_() {}

 protected:
  CharBoard board_;
};

TEST_F(BoardTest, InitializeTest) {
  EXPECT_EQ(board_.getCell(Coordinates(3, 3)), second_player);
  EXPECT_EQ(board_.getCell(Coordinates(4, 4)), second_player);
  EXPECT_EQ(board_.getCell(Coordinates(3, 4)), first_player);
  EXPECT_EQ(board_.getCell(Coordinates(4, 3)), first_player);
  EXPECT_EQ(board_.getCell(Coordinates(7, 7)), empty);
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
