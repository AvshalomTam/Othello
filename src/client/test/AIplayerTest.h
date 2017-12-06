#ifndef AIPLAYERTEST_H
#define AIPLAYERTEST_H
#include <gtest/gtest.h>
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/AIplayer.h"
#include "../include/ConsoleDisplay.h"

/**
 * Testing AIplayer.
 */
class AIplayerTest : public testing::Test {
 public:
  AIplayerTest(): board_(), judge_(), gameflow_(),  pl_(AIplayer(board_, judge_, gameflow_, second_player)) {}

  virtual void SetUp() {
    Coordinates move = Coordinates(2, 3);
    judge_.turnTiles(board_, move, first_player); //actually puts in cell 3,4
  }

  /**
  * making another 2 moves in the game by turning tiles in the board.
  */
  void setUp2() {
    Coordinates move = Coordinates(2, 2);
    judge_.turnTiles(board_, move, second_player); //actually puts in cell 3,3
    move = Coordinates(2, 1);
    judge_.turnTiles(board_, move, first_player); //actually puts in cell 3,2
  }

  /**
  * making another 2 moves in the game by turning tiles in the board.
  */
  void setUp3() {
    Coordinates move = Coordinates(1, 1);
    judge_.turnTiles(board_, move, second_player); //actually puts in cell 2,2
    move = Coordinates(0, 1);
    judge_.turnTiles(board_, move, first_player); //actually puts in cell 1,2
  }
 protected:
  CharBoard board_;
  BasicRules judge_;
  AIplayer pl_;
  ConsoleDisplay gameflow_;
};

//testing getMove function several times
TEST_F(AIplayerTest, minmax_calculate) {
  EXPECT_EQ(pl_.getMove().toString(), "(2,2)");
  setUp2();
  EXPECT_EQ(pl_.getMove().toString(), "(1,1)");
  setUp3();
  EXPECT_EQ(pl_.getMove().toString(), "(0,0)");
}


#endif //AIPLAYERTEST_H
