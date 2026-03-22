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
    std::vector<Entity> collection;
    ~Character();
private:
    int inputIdx;
    std::string name;
};

#endif // CHARACTER_H
