#include "itemlist.h"

ItemList::ItemList(){
    Item brick("Brick","Block"); // Blocks incoming dmg for 1 attack (can stack)
    Item vial("Vial","Poison"); // Deals dmg each turn (can stack)
    Item bandage("Bandage","Regenerate"); // Regenerates hp over time (can stack)
    Item bomb("Bomb","Explode"); // Deals damage 1 time next opponent turn
    Item rock("Rock","Strength"); // Increases dmg output
    Item crystal("Crystal","Nothing"); // Does nothing
    list = {brick, vial, bandage, bomb, rock, crystal};
}
