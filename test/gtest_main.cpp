// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "gtest/gtest.h"
#include "BoardTest.h"
#include "BasicRulesTest.h"
#include "AIplayerTest.h"
#include "CoordinatesTest.h"

GTEST_API_ int gtest_main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}