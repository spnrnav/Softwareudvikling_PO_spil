#ifndef ENTITYLIST_H
#define ENTITYLIST_H
#include "entity.h"
#include <vector>

class EntityList
{
public:
    EntityList();
    std::vector<Entity> list;
    ~EntityList();
};
#endif
