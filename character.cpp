#include "character.h"
#include <iostream>
#include "enemyList.h"

Character::Character() {}

Character::Character(std::string characterName){
    name = characterName;
    EnemyList monster;
    addMonster(monster.list[0]);
    addMonster(monster.list[0]);
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
