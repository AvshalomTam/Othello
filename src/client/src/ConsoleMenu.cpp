#include "../include/ConsoleMenu.h"
#include <iostream>
using namespace std;

void ConsoleMenu::printMenu() {
	cout << endl << "\tOTHELLO" << endl << endl;
	cout << "Choose an opponent type:" << endl << endl;
	cout << "1. a human local player" << endl;
	cout << "2. an AI player" << endl;
	cout << "3. a remote player" << endl << endl;
	this->setGameType();
}

void ConsoleMenu::setGameType() {
	char choice;
	while (true) {
		cout << "Your choice: ";
		cin >> choice;
		if (choice == '1') {
			this->type_ = local;
			break;
		}
		if (choice == '2') {
			this->type_ = computer;
			break;
		}
		if (choice == '3') {
			this->type_ = remote;
			break;
		}
		cout << "wrong input" << endl;
	}
}