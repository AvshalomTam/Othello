//
// Created by steve on 11/15/17.
//

#include <gtest/gtest.h>
#include "factorial.h"

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(5), 120);
  EXPECT_EQ(factorial(8), 40320);
}

TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HandlesNegativeInput) {
  EXPECT_EQ(factorial(-1), 1);
  EXPECT_EQ(factorial(-5), 1);
}