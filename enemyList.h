#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include "entity.h"
#include <vector>

class EnemyList
{
public:
    EnemyList();
    std::vector<Entity> list;
    ~EnemyList();
};
#endif
