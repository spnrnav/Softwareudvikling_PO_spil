#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "entity.h"

class Character
{
public:
    Character();
    Character(std::string);
    std::string getName();
    bool collectionLimit();
    void addMonster(Entity);
    void replaceMonster(Entity, int);
    ~Character();
private:
    int inputIdx;
    std::string name;
    std::vector<Entity> collection;
};

#endif // CHARACTER_H
