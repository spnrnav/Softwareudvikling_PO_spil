#include "character.h"
#include <iostream>
#include "entityList.h"

Character::Character() {}

Character::Character(std::string characterName){
    name = characterName;
    EntityList monster;
    addMonster(monster.list[0]);
    addMonster(monster.list[0]);
}



bool Character::collectionLimit(){
    return (collection.size() < 4); // True -> collection clear for addition, False -> collection limit reached
}

std::string Character::getName(){
    return name;
}

void Character::addMonster(Entity monster, bool dev){
    if ((collectionLimit()) || (dev)){
        collection.push_back(monster);
    }
    else {
        std::cout << "Collection full, choose monster to replace: ";
        std::cin >> inputIdx;
        if (inputIdx < 1){
            std::cout << "Invalid index, defaulting to 1\n";
            inputIdx = 1;
        }
        else if (inputIdx > 4){
            std::cout << "Invalid index, defaulting to 4\n";
            inputIdx = 4;
        }
        replaceMonster(monster, (inputIdx - 1));
    }
}

void Character::removeMonster(int idx){
    collection.erase(collection.begin() + idx);
}

void Character::replaceMonster(Entity newMonster, int idx){
    collection[idx] = newMonster;
}

std::string Character::getMostUsedItem(){
    int mostUses = -1;
    mostUsedItem = "N/A";
    for (int i = 0; i < collection.size(); ++i){
        for (int j = 0; j < collection[i].getEquippedItems().size(); ++i){
            if (mostUses < collection[i].getEquippedItems()[j].getUses()){
                mostUses = collection[i].getEquippedItems()[j].getUses();
                mostUsedItem = collection[i].getEquippedItems()[j].getName();
            }
        }
    }
    return mostUsedItem;
}

std::string Character::getMostUsedEntity(){
    int mostUses = -1;
    mostUsedEntity = "N/A";
    for (int i = 0; i < collection.size(); ++i){
        if (mostUses < collection[i].getUses()){
            mostUses = collection[i].getUses();
            mostUsedEntity = collection[i].getName();
        }
    }
    return mostUsedEntity;
}

Character::~Character(){}
