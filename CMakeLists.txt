cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(gtest/googletest-master)
include_directories(gtest/googletest-master/googletest/include)
include_directories(gtest/googletest-master/googlemock/include)

set(SOURCE_FILES
        include/AIplayer.h
        include/BasicRules.h
        include/Board.h
        include/CharBoard.h
        include/Coordinates.h
        include/Game.h
        include/GameLogic.h
        include/HumanPlayer.h
        include/Player.h
        src/AIplayer.cpp
        src/BasicRules.cpp
        src/Board.cpp
        src/CharBoard.cpp
        src/Coordinates.cpp
        src/Game.cpp
        src/GameLogic.cpp
        src/HumanPlayer.cpp
        src/main.cpp
        src/Player.cpp)

set(TEST_FILES
        test/gtest_main.cpp
        include/AIplayer.h
        include/BasicRules.h
        include/Board.h
        include/CharBoard.h
        include/Coordinates.h
        include/Game.h
        include/GameLogic.h
        include/HumanPlayer.h
        include/Player.h
        src/AIplayer.cpp
        src/BasicRules.cpp
        src/Board.cpp
        src/CharBoard.cpp
        src/Coordinates.cpp
        src/Game.cpp
        src/GameLogic.cpp
        src/HumanPlayer.cpp
        src/Player.cpp
        test/BoardTest.h test/GameLogicTest.h)

add_executable(Othello ${SOURCE_FILES})
add_executable(Test ${TEST_FILES})

target_link_libraries(Test gtest gtest_main)