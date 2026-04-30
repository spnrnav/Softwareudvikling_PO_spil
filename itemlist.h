#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "item.h"
#include <vector>

class ItemList
{
public:
    ItemList();
    std::vector<Item> list;
    ~ItemList(){}
};

#endif // ITEMLIST_H
