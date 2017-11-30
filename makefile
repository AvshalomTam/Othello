# EM168887
# Steve Gutfreund

a.out: main.o Board.o CharBoard.o Coordinates.o Game.o HumanPlayer.o Player.o GameLogic.o BasicRules.o AIplayer.o Menu.o ConsoleMenu.o Display.o ConsoleDisplay.o PreviousInfo.o
	g++ main.o Board.o CharBoard.o Coordinates.o Game.o HumanPlayer.o Player.o GameLogic.o BasicRules.o AIplayer.o Menu.o ConsoleMenu.o Display.o ConsoleDisplay.o PreviousInfo.o

main.o: main.cpp include/Game.h
	g++ -c main.cpp

Board.o: include/Coordinates.h src/Board.cpp include/Board.h
	g++ -c src/Board.cpp

CharBoard.o:	src/CharBoard.cpp include/CharBoard.h include/Board.h
	g++ -c src/CharBoard.cpp

Coordinates.o: src/Coordinates.cpp include/Coordinates.h
	g++ -c src/Coordinates.cpp

Game.o: include/HumanPlayer.h include/GameLogic.h src/Game.cpp include/Game.h
	g++ -c src/Game.cpp

HumanPlayer.o: include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h
	g++ -c src/HumanPlayer.cpp

Player.o: include/Coordinates.h src/Player.cpp include/Player.h
	g++ -c src/Player.cpp

GameLogic.o: include/Coordinates.h include/Board.h src/GameLogic.cpp include/GameLogic.h
	g++ -c src/GameLogic.cpp

BasicRules.o: include/Board.h include/Coordinates.h include/GameLogic.h src/BasicRules.cpp include/BasicRules.h
	g++ -c src/BasicRules.cpp

AIplayer.o:	include/Coordinates.h include/Board.h include/GameLogic.h include/Player.h src/AIplayer.cpp include/AIplayer.h
	g++ -c src/AIplayer.cpp

Menu.o: src/Menu.cpp include/Menu.h
	g++ -c src/Menu.cpp

ConsoleMenu.o:  src/ConsoleMenu.cpp include/ConsoleMenu.h include/Menu.h
	g++ -c src/ConsoleMenu.cpp

Display.o: src/Display.cpp include/Display.h
	g++ -c src/Display.cpp

ConsoleDisplay.o:  src/ConsoleDisplay.cpp include/ConsoleDisplay.h include/Display.h
	g++ -c src/ConsoleDisplay.cpp

PreviousInfo.o:	src/PreviousInfo.cpp include/PreviousInfo.h include/Coordinates.h include/Player.h
	g++ -c src/PreviousInfo.cpp

run:
	./a.out

clean:
	rm -f *.o a.out

memory:
	valgrind ./a.out

full_memory:
	valgrind --leak-check=full ./a.out
