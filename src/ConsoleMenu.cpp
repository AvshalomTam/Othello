// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/ConsoleMenu.h"
#include <iostream>
using namespace std;

void ConsoleMenu::printMenu() {
  cout << endl << "\tOTHELLO" << endl << endl;
  cout << "Who is your opponent?" << endl << endl;
  cout << "(P) player" << endl;
  cout << "(C) computer" << endl << endl;
  this->setGameType();
}

void ConsoleMenu::setGameType() {
  char choice;
  while (true) {
    cout << "Your choice: ";
    cin >> choice;
    if (choice == 'P' || choice == 'p') {
      this->type_ = local;
      break;
    }
    if (choice == 'C' || choice == 'c') {
      this->type_ = computer;
      break;
    }
    cout << "wrong input" << endl;
  }
}