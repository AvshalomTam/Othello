#include "../include/Menu.h"

void Menu::title(string title) {
    this->title_ = title;
}

void Menu::addMenuOption(char key, string description) {
    this->options[key] = description;
}

void Menu::subTitle(string sub_title) {
    this->sub_title_ = sub_title;
}

Menu::Menu() {
    this->title_ = "";
    this->sub_title_ = "";
}
