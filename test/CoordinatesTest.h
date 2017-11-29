//
// Created by avshalom on 11/29/17.
//

#ifndef COORDINATESTEST_H
#define COORDINATESTEST_H
#include <gtest/gtest.h>
#include "../include/Coordinates.h"

class CoordinatesTest : public testing::Test {
 public:
  CoordinatesTest() : coor1("(1,2)"), coor2(3,5), coor3() {}
  virtual void SetUp() {
    coor3 = coor1.move(coor2);
  }
 protected:
  Coordinates coor1, coor2, coor3;
};

//testing move function
TEST_F(CoordinatesTest, Move) {
  Coordinates tempCoor = Coordinates(4,7);
  cout << coor3.toString();
  EXPECT_EQ(coor3.toString(), tempCoor.toString());
}

//TEST_F(CoordinatesTest, MoveTest) {
  //Coordinates tempCoor = Coordinates(4,7);
  //EXPECT_EQ(coor3.toString(), tempCoor.toString());
//}
/*
//testing isEqual function.
TEST_F(CoordinatesTest, isEqualTest) {
  EXPECT_TRUE(coor1.isEqual(Coordinates(4,7)));
}*/

#endif //COORDINATESTEST_H

