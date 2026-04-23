#ifndef COMBAT_H
#define COMBAT_H
#include "entity.h"
#include "character.h"
#include "entityList.h"

class Combat
{
public:
    Combat();
    int generateRandomInt(int=100,int=0);
    void getIntInput();
    void getStrInput();
    void enemyTurn(Character&, Entity&, int);
    void allyTurn(Character&, Entity&, int);
    void battle(Character&, int);
    ~Combat();
private:
    //Entity mEnemy;
    int mMonsterIdx;
    EntityList monster;
    std::string lineSeperator = "-----------------------------\n";
    int inputInt;
    std::string inputStr;
};

#endif // COMBAT_H
