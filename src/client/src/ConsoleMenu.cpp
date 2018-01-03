#include <iostream>
#include "../include/ConsoleMenu.h"

void ConsoleMenu::printMenu() {
    if (this->title_ != "") {
        cout << endl << "\t" + this->title_;
    }
    cout << endl << endl;
    if (this->sub_title_ != "") {
        cout << this->sub_title_ << endl << endl;
    }
    for (map<char, string>::iterator it = this->options.begin(); it != this->options.end(); ++it) {
        cout <<"(" << it->first << ")" << " " << it->second << endl;
    }
    cout << endl;
}

char ConsoleMenu::getChoice() {
    char choice;
    while (true) {
        cout << "Your choice: ";
        cin >> choice;
        for (map<char, string>::iterator it = this->options.begin(); it != this->options.end(); ++it) {
            if (choice == it->first) {
                return choice;
            }
        }
        cout << "wrong input" << endl;
    }
}
