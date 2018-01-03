#ifndef OTHELLO_TMP_H
#define OTHELLO_TMP_H
#include <string>
#include <map>
using namespace std;

class Menu {
  public:
    Menu();
    void title(string title);
    void subTitle(string sub_title);
    void addMenuOption(char key, string description);
    virtual char getChoice() = 0;
    virtual void printMenu() = 0;
  protected:
    string title_;
    string sub_title_;
    map<char, string> options;
};

#endif //OTHELLO_TMP_H
