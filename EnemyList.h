#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include "entity.h"
#include <vector>

Entity hest("hest",4,1);
Entity weakGoblin("Weak Goblin",4,2);
Entity strongGoblin("Strong Goblin",8,3);
Entity strongerGoblin("Stronger Goblin",10,4);
Entity strongestGoblin("Strongest Goblin",15,5);
Entity abeKongen("Abe Kongen",30,5);
Entity enhjørning("Enhjørning",50,8);
Entity drage("Drage",100,10);

std::vector<Entity> enemyList = {hest, weakGoblin, strongGoblin, strongerGoblin, strongestGoblin, abeKongen, enhjørning, drage};

#endif // ENEMYLIST_H
