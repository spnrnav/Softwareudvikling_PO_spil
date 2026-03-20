#include "entity.h"

Entity::Entity() {}

Entity::Entity(std::string entityName, int health, int strength){
    name = entityName;
    hp = health;
    dmg = strength;
}

std::string Entity::getName(){
    return name;
}

int Entity::getHP(){
    return hp;
}

int Entity::getDmg(){
    return dmg;
}

Entity::~Entity(){}
