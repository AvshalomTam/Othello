// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include <iostream>
#include "../include/ConsoleGameFlow.h"

void ConsoleGameFlow::printCurrentBoard(Board &board) {
  cout << endl << "Current board:" << endl << endl;
  board.printBoard();
  cout << endl;
}

void ConsoleGameFlow::printPreviousMove(string name, string coordinate) {
  cout << name << " played " << coordinate << endl << endl;
}

void ConsoleGameFlow::printTurn(string name) {
  cout << name << ": It's your move." << endl;
}

void ConsoleGameFlow::printNoMove() {
  cout << "No possible moves. Play passes to the other player. Press ENTER to continue." << endl;
  cin.get();
}

void ConsoleGameFlow::printOptions(list<Coordinates> &options) {
  //printing the player's options
  cout << "Your possible moves: ";
  for (list<Coordinates>::iterator it = options.begin(); it != options.end(); ++it) {
    if (it == options.begin()) {
      cout << it->move(Coordinates(1, 1)).toString();
    }
    else {
      cout << "," << it->move(Coordinates(1, 1)).toString();
    }
  }
  cout << endl;
}

void ConsoleGameFlow::printMoveRequest() {
  cout << "Please enter your move row,col: ";
}

void ConsoleGameFlow::printInputError(const char* error) {
  cout << endl << error << endl << endl;
}

void ConsoleGameFlow::printResult(string name) {
  cout << endl << "G A M E   O V E R" << endl << endl;
  if (!name.compare("draw")) {
    cout << "DRAW GAME !!!!";
  }
  else {
    cout << name << " wins the game.";
  }
  cout << endl << endl;
}

void ConsoleGameFlow::pcCalculating() {
  cout << "Computer is calculating a move. Press ENTER to continue.";
  cin.get();
  cout << endl;
}

string ConsoleGameFlow::input() {
  string s;
  cin >> s;
  cin.get();
  return s;
}
