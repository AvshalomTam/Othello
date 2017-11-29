// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef COORDINATESTEST_H
#define COORDINATESTEST_H

#include <gtest/gtest.h>
class CoordinatesTest : public testing::Test {
 public:

 protected:
};

TEST_F(CoordinatesTest, Move) {
  EXPECT_EQ(1, 1);
}

#endif //COORDINATESTEST_H
