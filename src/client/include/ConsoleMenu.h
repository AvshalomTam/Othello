#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include "Menu.h"

/**
 * Menu at beginning of the game, using the console.
 */
class ConsoleMenu : public Menu {
 public:
  /**
   * Prints a menu. Let's the player choose between playing against pc or player.
   */
  void printMenu();
  /**
   * Sets the type of the game (versus pc or player).
   */
  void setGameType();
};

#endif //CONSOLEMENU_H
