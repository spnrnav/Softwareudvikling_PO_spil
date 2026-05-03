#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include "item.h"
#include <vector>

class Entity
{
public:
    Entity();
    Entity(std::string,int,int);
    std::string getName();
    int getHP();
    int getDmg();
    int getBaseHP(){return baseHp;}
    int getBaseDmg(){return baseDmg;}
    int getStrength(){return strength;}

    void dealDmg(int);
    void heal(int);
    void addBlock(int b){defence += b;}
    void addStrength(int s){strength += s;}
    void resetHP(){hp = baseHp;}
    void resetDmg(){dmg = baseDmg;}
    void resetAll() {resetDmg();resetHP();resetStatus();}

    void equipItem(Item);
    std::vector<Item> getEquippedItems(){return equippedItems;}

    void addStatus(std::string);
    void removeStatus(int);
    void resetStatus();
    std::vector<std::string> getStatusList(){return statusList;}

    ~Entity();
private:
    std::string name;
    int hp;
    int dmg;
    int baseHp = hp;
    int baseDmg = dmg;
    int defence = 0;
    int strength = 0;
    std::vector<Item> equippedItems;
    std::vector<std::string> statusList;
};

#endif // ENTITY_H
