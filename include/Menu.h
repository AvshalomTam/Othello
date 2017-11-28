// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef MENU_H
#define MENU_H
enum game_type {local, computer, online};

/**
 * Menu at opening of the game.
 */
class Menu {
 public:
  /**
   * Prints a menu. Let's the player choose between playing against pc or player.
   */
  virtual void printMenu() = 0;
  /**
   * Sets the type of the game (versus pc or player).
   */
  virtual void setGameType() = 0;
  /**
   * @return type of game
   */
  game_type getGameType();

 protected:
  game_type type_;
};

#endif //MENU_H
