#ifndef OTHELLO_CONSOLETMP_H
#define OTHELLO_CONSOLETMP_H

#include "Menu.h"
class ConsoleMenu : public Menu {
  public:
    void printMenu();
    char getChoice();
};

#endif //OTHELLO_CONSOLETMP_H
