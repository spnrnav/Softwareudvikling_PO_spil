#ifndef MENU_H
#define MENU_H
#include "character.h"
#include <iostream>
#include "databaseComs.h"
//#include "enemylist.h"

class Menu
{
public:
    Menu();
    void getIntInput();
    void getStrInput();
    void main();
    void sub(Character&);
    void manage(Character&);
    void displayStatistics(Character&);
    void loadMenu();
    void saveMenu(Character&);
    void combat(Character&);
    void caveCombat(Character&);
    void updateDeathcount(Character&);
    ~Menu();
private:
    std::string lineSeperator = "-----------------------------\n";
    int inputInt;
    std::string inputStr;
    int deathCount = 0;
    DatabaseComs db;
};

#endif // MENU_H
