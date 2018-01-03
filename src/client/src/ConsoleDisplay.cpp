#include <iostream>
#include "../include/ConsoleDisplay.h"

void ConsoleDisplay::printCurrentBoard(Board &board) {
  cout << endl << "Current board:" << endl << endl;
  board.printBoard();
  cout << endl;
}

void ConsoleDisplay::printPreviousMove(string name, string coordinate) {
  cout << name << " played " << coordinate << endl << endl;
}

void ConsoleDisplay::printTurn(string name) {
  cout << name <<" it's your turn." << endl;
}

void ConsoleDisplay::printNoMove() {
  cout << "No possible moves. Play passes to the other player. Press ENTER to continue." << endl;
  cin.get();
}

void ConsoleDisplay::printOptions(list<Coordinates> &options) {
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

void ConsoleDisplay::printMoveRequest() {
  cout << "Please enter your move row,col: ";
}

void ConsoleDisplay::printInputError(const char* error) {
  cout << endl << error << endl << endl;
}

void ConsoleDisplay::printResult(string name) {
  cout << endl << "G A M E   O V E R" << endl << endl;
  if (!name.compare("draw")) {
    cout << "DRAW GAME !!!!";
  }
  else {
    cout << name << " wins the game.";
  }
  cout << endl << endl;
}

void ConsoleDisplay::pcCalculating() {
  cout << "Computer is calculating a move. Press ENTER to continue.";
  cin.get();
  cout << endl;
}

string ConsoleDisplay::input() {
  string s;
  cin >> s;
  cin.get();
  return s;
}

void ConsoleDisplay::waitingForPlayer() {
  cout << "waiting for other player's move..." << endl << endl;
}

void ConsoleDisplay::waitForOtherPlayerConnect() {
  cout << "Waiting for other player to join..." << endl;
}

void ConsoleDisplay::serverDisconnect(const char *str) {
  cout << str << endl;
}

void ConsoleDisplay::printListGames(vector<char *> list) {
  cout << endl;
  int i = 1;
  for(vector<char*>::iterator it = list.begin(); it != list.end(); ++it) {
    cout << i++ << ".\t";
    cout << *it << endl;
  }
  if (list.empty()) {
    cout << "No available games." << endl;
  }
  cout << endl;
  cout << "Press any key (then hit ENTER) to continue." << endl;
  char c;
  cin >> c;
}

string ConsoleDisplay::getGameName() {
  cout << "Please enter name of game: ";
  string name;
  cin >> name;
  cout << endl;
  return name;
}

void ConsoleDisplay::printNameOccupied() {
  cout << "Name of game already in use." << endl << endl;
  cout << "Press any key (then hit ENTER) to continue." << endl;
  char c;
  cin >> c;
}

void ConsoleDisplay::printUnableJoin() {
  cout << "Can't join this game." << endl << endl;
  cout << "Press any key (then hit ENTER) to continue." << endl;
  char c;
  cin >> c;
}
