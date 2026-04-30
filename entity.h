#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity
{
public:
    Entity();
    Entity(std::string,int,int);
    std::string getName();
    int getHP();
    int getDmg();
    void dealDmg(int);
    ~Entity();
private:
    std::string name;
    int hp;
    int dmg;
};

#endif // ENTITY_H
