#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "entity.h"
#include "item.h"

class Character
{
public:
    Character();
    Character(std::string);
    void setName(std::string newName){name = newName;}
    std::string getName();
    bool collectionLimit();
    void addMonster(Entity, bool dev = false);
    void removeMonster(int);
    void replaceMonster(Entity, int);
    std::vector<Entity> collection;
    void addItem(Item newItem) {items.push_back(newItem);}
    void removeItem(int idx) {items.erase(items.begin() + idx);}
    std::vector<Item> getItems(){return items;}
    int getKillCount(){return killCount;}
    void addKill(int kills = 1){killCount += kills;}
    std::string getMostUsedItem();
    std::string getMostUsedEntity();
    ~Character();
private:
    int inputIdx;
    std::string name;
    std::vector<Item> items;
    int killCount = 0;
    std::string mostUsedItem;
    std::string mostUsedEntity;
};

#endif // CHARACTER_H
