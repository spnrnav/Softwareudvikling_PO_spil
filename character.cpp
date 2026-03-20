#include "character.h"

Character::Character() {}

Character::Character(std::string characterName){
    name = characterName;
}

std::string Character::getName(){
    return name;
}

void Character::addMonster(Entity monster){
    Entity hest("hest",4,1);
    collection.push_back(hest);
    collection.push_back(hest);
}

Character::~Character(){}
