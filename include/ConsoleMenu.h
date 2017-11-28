// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include "Menu.h"
class ConsoleMenu : public Menu {
 public:
  void printMenu();
  void setGameType();
};

#endif //CONSOLEMENU_H
