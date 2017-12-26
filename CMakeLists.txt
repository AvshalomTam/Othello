cmake_minimum_required(VERSION 3.8)
project(Othello)
find_package(Threads)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(gtest/googletest-release-1.8.0)
include_directories(gtest/googletest-release-1.8.0/googletest/include)
include_directories(gtest/googletest-release-1.8.0/googlemock/include)

set(GAME_FILES src/client/main.cpp src/server/include/ClientHandler.h)
set(TEST_FILES
        src/client/test/gtest_main.cpp
        src/client/test/BoardTest.h
        src/client/test/BasicRulesTest.h
        src/client/test/AIplayerTest.h
        src/client/test/CoordinatesTest.h src/server/src/Command.cpp src/server/include/Command.h src/server/src/CommandsManager.cpp src/server/include/CommandsManager.h src/server/src/StartCommand.cpp src/server/include/StartCommand.h src/server/src/ListCommand.cpp src/server/include/ListCommand.h src/server/src/JoinCommand.cpp src/server/include/JoinCommand.h src/server/src/PlayCommand.cpp src/server/include/PlayCommand.h src/server/src/CloseCommand.cpp src/server/include/CloseCommand.h src/server/include/ClientHandler.h src/server/src/ClientHandler.cpp src/server/include/GameRoom.h src/server/src/GameRoom.cpp)
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
        src/client/include/MoveTracker.h
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
        src/client/src/MoveTracker.cpp
        src/client/src/RemotePlayer.cpp
        src/client/include/RemotePlayer.h
        src/client/src/Listener.cpp
        src/client/include/Listener.h
        src/client/include/ServerListener.h
        src/client/src/ServerListener.cpp
        src/client/src/PlayerFactory.cpp
        src/client/include/PlayerFactory.h)
set(SERVER_FILES
        src/server/main_s.cpp
        src/server/src/Server.cpp
        src/server/include/Server.h src/server/src/Command.cpp src/server/include/Command.h src/server/src/CommandsManager.cpp src/server/include/CommandsManager.h src/server/src/StartCommand.cpp src/server/include/StartCommand.h src/server/src/ListCommand.cpp src/server/include/ListCommand.h src/server/src/JoinCommand.cpp src/server/include/JoinCommand.h src/server/src/PlayCommand.cpp src/server/include/PlayCommand.h src/server/src/CloseCommand.cpp src/server/include/CloseCommand.h src/server/include/ClientHandler.h src/server/src/ClientHandler.cpp src/server/include/GameRoom.h src/server/src/GameRoom.cpp)

add_executable(Othello ${SOURCE_FILES} ${GAME_FILES})
add_executable(Test ${SOURCE_FILES} ${TEST_FILES})
add_executable(Server_Re6 ${SERVER_FILES})

target_link_libraries(Test gtest gtest_main)
target_link_libraries(Server_Re6 ${CMAKE_THREAD_LIBS_INIT})