#include "character.h"
#include <iostream>

Character::Character() {}

Character::Character(std::string characterName){
    name = characterName;
    Entity hest("hest",4,1);
    addMonster(hest);
    addMonster(hest);
}



bool Character::collectionLimit(){
    return (collection.size() < 4); // True -> collection clear for addition, False -> collection limit reached
}

std::string Character::getName(){
    return name;
}

void Character::addMonster(Entity monster){
    if (collectionLimit()){
        collection.push_back(monster);
    }
    else {
        std::cout << "Collection full, choose monster to replace: ";
        std::cin >> inputIdx;
        replaceMonster(monster, (inputIdx - 1));
    }
}

void Character::replaceMonster(Entity newMonster, int idx){
    collection[idx] = newMonster;
}

Character::~Character(){}
