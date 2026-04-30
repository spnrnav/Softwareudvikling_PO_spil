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
    ~Item(){};
private:
    std::string name;
    std::string status;
};

#endif // ITEM_H
