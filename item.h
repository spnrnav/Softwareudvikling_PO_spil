#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
    Item(){};
    Item(std::string n, std::string e) {name = n; status = e;}
    std::string getName(){return name;}
    std::string getStatus(){return status;}
    void addUse(int newUses = 1){itemUses += newUses;}
    int getUses(){return itemUses;}
    ~Item(){};
private:
    std::string name;
    std::string status;
    int itemUses = 0;
};

#endif // ITEM_H
