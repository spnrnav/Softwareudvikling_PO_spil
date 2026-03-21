#ifndef MENU_H
#define MENU_H
#include "character.h"
#include <iostream>

class Menu
{
public:
    Menu();
    void getIntInput();
    void getStrInput();
    void main();
    void sub();
    void combat();
    ~Menu();
private:
    std::string lineSeperator = "-----------------------------\n";
    int inputInt;
    std::string inputStr;
    int menuLvl = 0;
};

#endif // MENU_H
