#ifndef CAVE_H
#define CAVE_H
#include "entity.h"
#include "item.h"
#include "character.h"

class Cave
{
public:
    Cave(Character&);
    void generateCave(Character&);
    Item getReward() {return reward;}
    std::vector<int> getHostiles(){return hostilesIdx;}
    int generateRandomInt(int=100,int=0);
    ~Cave(){};
private:
    std::vector<int> hostilesIdx;
    Item reward;
};

#endif // CAVE_H
