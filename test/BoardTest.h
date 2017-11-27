// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"

class BoardTest: public testing::Test {
 public:
  BoardTest(): b1() {}

 protected:
  CharBoard b1;
};

TEST_F(BoardTest, InitializeTest) {
  EXPECT_EQ(b1.getCell(Coordinates(3, 3)), second_player);
  EXPECT_EQ(b1.getCell(Coordinates(4, 4)), second_player);
  EXPECT_EQ(b1.getCell(Coordinates(3, 4)), first_player);
  EXPECT_EQ(b1.getCell(Coordinates(4, 3)), first_player);
  EXPECT_EQ(b1.getCell(Coordinates(7, 7)), empty);
}

TEST_F(BoardTest, MoveTest) {
  b1.setCell(Coordinates(5, 6), first_player);
  EXPECT_EQ(b1.getCell(Coordinates(5, 6)), first_player);
  b1.setCell(Coordinates(1, 2), second_player);
  EXPECT_EQ(b1.getCell(Coordinates(1, 2)), second_player);
}

TEST_F(BoardTest, ScoreTest) {
  b1.setCell(Coordinates(5, 6), first_player);
  EXPECT_EQ(b1.getScore(first_player), 3);
  EXPECT_EQ(b1.getScore(second_player), 2);
}

#endif //BOARDTEST_H
