#ifndef COMBAT_H
#define COMBAT_H
#include "entity.h"
#include "character.h"

class Combat
{
public:
    Combat();
    Combat(Entity);
    int generateRandomInt(int=100,int=0);
    void battle();
    ~Combat();
private:
    Entity mEnemy;
};

#endif // COMBAT_H
