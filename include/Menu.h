// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef MENU_H
#define MENU_H
enum game_type {local, computer, online};

class Menu {
 public:
  virtual void printMenu() = 0;
  virtual void setGameType() = 0;
  game_type getGameType();

 protected:
  game_type type_;
};

#endif //MENU_H
