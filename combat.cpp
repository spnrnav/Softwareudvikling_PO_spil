#include "combat.h"
#include <ctime>

Combat::Combat() {}
Combat::Combat(Entity enemy){
    mEnemy = enemy;
}

int Combat::generateRandomInt(int highBound, int lowBound){
    srand(time(NULL)); // resets seed to generate random number
    return (rand() % highBound + lowBound);
}

void Combat::battle(){
    generateRandomInt();
}

Combat::~Combat(){}
