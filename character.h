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
    void addMonster(Entity);
    ~Character();
private:
    std::string name;
    std::vector<Entity> collection;
};

#endif // CHARACTER_H
