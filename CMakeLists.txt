cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(gtest/googletest-release-1.8.0)
include_directories(gtest/googletest-release-1.8.0/googletest/include)
include_directories(gtest/googletest-release-1.8.0/googlemock/include)

set(GAME_FILES src/client/main.cpp)
set(TEST_FILES
        src/client/test/gtest_main.cpp
        src/client/test/BoardTest.h
        src/client/test/BasicRulesTest.h
        src/client/test/AIplayerTest.h
        src/client/test/CoordinatesTest.h)
set(SOURCE_FILES
        src/client/include/AIplayer.h
        src/client/include/BasicRules.h
        src/client/include/Board.h
        src/client/include/CharBoard.h
        src/client/include/Coordinates.h
        src/client/include/Game.h
        src/client/include/GameLogic.h
        src/client/include/HumanPlayer.h
        src/client/include/Player.h
        src/client/include/Menu.h
        src/client/include/ConsoleMenu.h
        src/client/include/Display.h
        src/client/include/ConsoleDisplay.h
        src/client/include/PreviousInfo.h
        src/client/src/AIplayer.cpp
        src/client/src/BasicRules.cpp
        src/client/src/Board.cpp
        src/client/src/CharBoard.cpp
        src/client/src/Coordinates.cpp
        src/client/src/Game.cpp
        src/client/src/GameLogic.cpp
        src/client/src/HumanPlayer.cpp
        src/client/src/Player.cpp
        src/client/src/Menu.cpp
        src/client/src/ConsoleMenu.cpp
        src/client/src/Display.cpp
        src/client/src/ConsoleDisplay.cpp
        src/client/src/PreviousInfo.cpp src/client/src/RemotePlayer.cpp src/client/include/RemotePlayer.h src/client/src/Listener.cpp src/client/include/Listener.h)
set(SERVER_FILES
        src/server/main_s.cpp
        src/server/Server.cpp
        src/server/Server.h)

add_executable(Othello ${SOURCE_FILES} ${GAME_FILES})
add_executable(Test ${SOURCE_FILES} ${TEST_FILES})
add_executable(Server_Re6 ${SERVER_FILES})

target_link_libraries(Test gtest gtest_main)