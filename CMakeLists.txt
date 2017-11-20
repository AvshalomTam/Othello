cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(Othello ${SOURCE_FILES})