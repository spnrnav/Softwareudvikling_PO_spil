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
    int damage = dmg + strength;
    strength = 0; // resets strength
    return damage;
}

void Entity::dealDmg(int damage){
    damage -= defence;
    if (damage > 0){
        hp -= damage;
        if (hp < 0){
            hp = 0;
        }
    }
    defence = 0; // Resets destroyed defence
}

void Entity::heal(int regen){
    if ((hp + regen) < baseHp){
        hp += regen;
    }
    else {
        hp = baseHp;
    }
}

void Entity::equipItem(Item newItem){
    equippedItems.push_back(newItem);
}

void Entity::addStatus(std::string status){
    statusList.push_back(status);
}

void Entity::removeStatus(int idx){
    statusList.erase(statusList.begin() + idx);
}

void Entity::resetStatus(){
    statusList.clear();
    defence = 0;
    strength = 0;
}

Entity::~Entity(){}
