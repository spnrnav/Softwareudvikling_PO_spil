#ifndef MENU_H
#define MENU_H
#include "character.h"
#include <iostream>
//#include "enemylist.h"

class Menu
{
public:
    Menu();
    void getIntInput();
    void getStrInput();
    void main();
    void sub(Character&);
    void combat(Character&);
    ~Menu();
private:
    std::string lineSeperator = "-----------------------------\n";
    int inputInt;
    std::string inputStr;
    int menuLvl = 0;
};

#endif // MENU_H
