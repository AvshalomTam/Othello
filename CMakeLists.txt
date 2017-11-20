cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(gtest_src)
include_directories(gtest_src/googletest/include)
include_directories(gtest_src/googlemock/include)

set(SOURCE_FILES src/main.cpp src/Board.cpp include/Board.h src/Player.cpp include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h src/Game.cpp include/Game.h src/Coordinates.cpp include/Coordinates.h src/BasicRules.cpp include/BasicRules.h src/CharBoard.cpp include/CharBoard.h src/GameLogic.cpp include/GameLogic.h test/gtest_main.cpp test/factorial.h test/factorial.cpp test/test_factorial.cpp src/AIplayer.cpp include/AIplayer.h)
set(TEST_SOURCE_FILES test/gtest_main.cpp test/factorial.cpp test/factorial.h test/test_factorial.cpp src/AIplayer.cpp include/AIplayer.h)
add_executable(Reversi ${SOURCE_FILES})
add_executable(Test ${TEST_SOURCE_FILES})
target_link_libraries(Reversi gtest gtest_main)
target_link_libraries(Test gtest gtest_main)