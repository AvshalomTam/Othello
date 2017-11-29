// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef AIPLAYERTEST_H
#define AIPLAYERTEST_H

#include <gtest/gtest.h>
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/AIplayer.h"

/**
 * Testing AIplayer.
 */
/*
class AIplayerTest : public testing::Test {
 public:
  AIplayerTest(): board_(), judge_(), pl_(AIplayer(board_, judge_, second_player)) {}

  virtual void SetUp() {
    Coordinates move = Coordinates(2, 3);
    judge_.turnTiles(board_, move, first_player); //actually puts in cell 3,4
  }

 protected:
  CharBoard board_;
  BasicRules judge_;
  AIplayer pl_;
};

TEST_F(AIplayerTest, minmax_calculate) {
  EXPECT_EQ(pl_.getMove().toString(), "(2,2)");
}*/
#endif //AIPLAYERTEST_H
