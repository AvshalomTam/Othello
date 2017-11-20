cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Board.cpp include/Board.h src/Coordinates.cpp include/Coordinates.h src/Game.cpp include/Game.h src/GameLogic.cpp include/GameLogic.h src/BasicRules.cpp include/BasicRules.h src/Player.cpp include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h src/CharBoard.cpp include/CharBoard.h src/AIplayer.cpp include/AIplayer.h)
add_executable(Othello ${SOURCE_FILES})