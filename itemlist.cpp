#include "itemlist.h"

ItemList::ItemList(){
    Item shell("Shell","Block");
    Item vial("Vial","Poison");
    Item bandage("Bandage","Regeneration");
    list = {shell, vial, bandage};
}
