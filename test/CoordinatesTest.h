// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef COORDINATESTEST_H
#define COORDINATESTEST_H

#include <gtest/gtest.h>
class CoordinatesTest : public testing::Test {
 public:
  CoordinatesTest() : coor1(Coordinates("1,2")), coor2(Coordinates(3, 5)), coor3(Coordinates()) {}
  virtual void SetUp() {
    coor3 = coor1.move(coor2);
  }
 protected:
  Coordinates coor1, coor2, coor3;
};

TEST_F(CoordinatesTest, MoveTest) {
  Coordinates tempCoor = Coordinates(4,7);
  EXPECT_EQ(coor3.toString(), tempCoor.toString());
}

//testing isEqual function.
TEST_F(CoordinatesTest, isEqualTest) {
  Coordinates c = Coordinates(4, 7);
  EXPECT_TRUE(coor3.isEqual(c));
  EXPECT_FALSE(coor1.isEqual(c));
}

#endif //OTHELLO_COORDINATESTEST_H
