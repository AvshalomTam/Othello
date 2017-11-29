// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "gtest/gtest.h"
#include "../include/CharBoard.h"
#include "../include/Board.h"
/**
 * Testing CharBoard class.
 */
class BoardTest : public testing::Test {
 public:
  BoardTest() : board_(), testBoard4(4), testBoard7(7) {}

 protected:
  CharBoard board_, testBoard4, testBoard7;
};

//test the correction of board's starting values of cells
TEST_F(BoardTest, InitializeTest) {
  EXPECT_EQ(board_.getCell(Coordinates(3, 3)), second_player) << "Cell(3,3) should be equal 2"; //actually 4,4 cell
  EXPECT_EQ(board_.getCell(Coordinates(4, 4)), second_player) << "Cell(4,4) should be equal 2"; //actually 5,5 cell
  EXPECT_EQ(board_.getCell(Coordinates(3, 4)), first_player) << "Cell(3,4) should be equal 1"; //actually 4,5 cell
  EXPECT_EQ(board_.getCell(Coordinates(4, 3)), first_player) << "Cell(4,3) should be equal 1"; //actually 5,4 cell
  for (int i = 0; i < board_.getSize(); i++) {
    for (int j = 0; j < board_.getSize(); j++) {
      if (!(((i == 3) && (j == 3)) || ((i == 4) && (j == 4)) || ((i == 3) && (j == 4)) || ((i == 4) && (j == 3)))) {
        EXPECT_EQ(board_.getCell(Coordinates(i, j)), empty) << "Every other Cell should be equal 0";
      }
    }
  }
}

//testing getSize function
TEST_F(BoardTest, SizeTest) {
  //testing the default size of board (which is 8 without any specific value given to board constructor)
  EXPECT_EQ(board_.getSize(), 8);
  //testing specific size of board given to board constructor.
  EXPECT_EQ(testBoard4.getSize(), 4);
  //testing another specific size of board given to board constructor.
  EXPECT_EQ(testBoard7.getSize(), 7);
}

//testing setCell function
TEST_F(BoardTest, MoveTest) {
  board_.setCell(Coordinates(5, 6), first_player);
  EXPECT_EQ(board_.getCell(Coordinates(5, 6)), first_player);
  board_.setCell(Coordinates(1, 2), second_player);
  EXPECT_EQ(board_.getCell(Coordinates(1, 2)), second_player);
}

//testing getScore function
TEST_F(BoardTest, ScoreTest) {
  board_.setCell(Coordinates(5, 6), first_player); //actually put X in (6,7) cell.
  // not valid move according to game rules. just to test getScore function.
  // should not turn any of the O cells, so finally: 3 Xs, 2 Os, and 8x8-3-2 = 59 empty cells.
  EXPECT_EQ(board_.getScore(first_player), 3) << "number of Xs is not 3" ;
  EXPECT_EQ(board_.getScore(second_player), 2) << "number of Os is not 2";
  EXPECT_EQ(board_.getScore(empty), 59) << "number of Os is not 59";
  //now another set of a cell, white one.
  board_.setCell(Coordinates(6, 6), second_player); //actually put O in (7,7) cell.
  // not valid move according to game rules. just to test getScore function.
  // should not turn any of the X cells, so finally: 3 Xs, 3 Os, and 8x8-3-3 = 58 empty cells.
  EXPECT_EQ(board_.getScore(first_player), 3) << "number of Xs is not 3" ;
  EXPECT_EQ(board_.getScore(second_player), 3) << "number of Os is not 3";
  EXPECT_EQ(board_.getScore(empty), 58) << "number of Os is not 58";

}
#endif //BOARDTEST_H
