// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/ConsoleMenu.h"
#include <iostream>
using namespace std;

void ConsoleMenu::printMenu() {
  cout << "\tOTHELLO" << endl << endl;
  cout << "Who is your opponent?" << endl << endl;
  cout << "(P) player" << endl;
  cout << "(C) computer" << endl << endl;
  this->setGameType();
}

void ConsoleMenu::setGameType() {
  char choice;
  cout << "Your choice: ";
  cin >> choice;
  if (choice == 'P') {
    this->type_ = local;
  }
  else if (choice == 'C') {
    this->type_ = computer;
  }
}