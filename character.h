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
    std::string getName();
    bool collectionLimit();
    void addMonster(Entity);
    void removeMonster(int);
    void replaceMonster(Entity, int);
    std::vector<Entity> collection;
    void addItem(Item newItem) {items.push_back(newItem);}
    void removeItem(int idx) {items.erase(items.begin() + idx);}
    std::vector<Item> getItems(){return items;}
    ~Character();
private:
    int inputIdx;
    std::string name;
    std::vector<Item> items;
};

#endif // CHARACTER_H
