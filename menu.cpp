#include "menu.h"
#include "combat.h"
//#include "enemylist.h"

Menu::Menu() {}

void Menu::getIntInput(){
    std::cin >> inputInt;
    std::cout << lineSeperator;
}

void Menu::getStrInput(){
    std::cin.ignore();
    getline(std::cin, inputStr, '\n');
    std::cout << lineSeperator;
}

void Menu::main(){
    bool menuActive = true;
    while (menuActive){
        std::cout << "----------Main menu----------\n"
                  << "1: New character\n"
                  << "2: Load character\n"
                  << "3: Quit game\n" + lineSeperator
                  << "Choose action: ";
        getIntInput();

        if (inputInt == 1){ // New character
            std::cout << "Enter character name: ";
            getStrInput();
            Character player(inputStr);
            std::cout << "Character \"" + inputStr + "\" created\n";
            sub(player);
        }
        else if (inputInt == 2){ // Load Character (implement later)
            std::cout << "action2\n";
        }
        else if (inputInt == 3){ // Quit game
            menuActive = false;
        }
        else{
            std::cout << "Invallid input\n";
        }
    }
}

void Menu::sub(Character& character){
    bool menuActive = true;
    while (menuActive){
        std::cout << "--------Adventure menu-------\n"
                  << "1: Fight monster\n"
                  << "2: Fight cave\n"
                  << "3: Manage monsters\n"
                  << "4: Quit adventure\n" + lineSeperator
                  << "Choose action: ";
        getIntInput();

        if (inputInt == 1){ // Fight monster
            combat(character);
        }
        else if (inputInt == 2){ // Fight cave
            menuActive = false;
        }
        else if (inputInt == 3){ // Manage monsters
            menuActive = false;
        }
        else if (inputInt == 4){ // Quit sub menu
            menuActive = false;
        }
        else{
            std::cout << "Invallid input\n";
        }
        if (deathCount == character.collection.size()){ // Quit sub menu if all allies are defeated
            menuActive = false;
        }
    }
}

void Menu::manage(Character& player){
    bool menuActive = true;
    while (menuActive){
        std::cout << "1: Release\n"
                  << "2: Give item\n"
                  << "3: Exit\n" + lineSeperator
                  << "Choose action: ";
        getIntInput();

        if (inputInt == 1){ // Remove ally monster
            for (int j = 0; j < player.collection.size(); j++){ // Display names of all allies
                std::cout << j+1 << ": " << player.collection[j].getName() << " (Hp: " << player.collection[j].getBaseHP() << ", Dmg: " << player.collection[j].getBaseDmg() << ")" << std::endl;
            }
            std::cout << "Choose ally to release: ";
            getIntInput();
            player.removeMonster(inputInt-1);
        }
        else if (inputInt == 2){ // Equip monster with item
            int itemIdx;
            for (int i = 0; i < player.getItems().size(); i++){
                std::cout << i+1 << ": " << player.getItems()[i].getName() << std::endl;
            }
            std::cout << "Choose item to equip: ";
            getIntInput();
            if ((inputInt >= 0) and (inputInt < player.getItems().size())){
                itemIdx = inputInt-1;
                for (int j = 0; j < player.collection.size(); j++){ // Display names of all allies
                    std::cout << j+1 << ": " << player.collection[j].getName() << " (Hp: " << player.collection[j].getBaseHP() << ", Dmg: " << player.collection[j].getBaseDmg() << ")" << std::endl;
                }
                std::cout << "Choose ally to equip " << player.getItems()[itemIdx].getName() << ": ";
                getIntInput();
                player.collection[inputInt-1].equipItem(player.getItems()[itemIdx]);
                player.removeItem(itemIdx);
            }
        }
        else if (inputInt == 3){
            break;
        }
        else{
            std::cout << "Invallid input\n";
        }
    }
}

void Menu::combat(Character& player){
    bool menuActive = true;
    while (menuActive){
        std::cout << "---------Combat menu---------\n"
                  << "1: Hest\n"
                  << "2: Weak Goblin\n"
                  << "3: Strong Goblin\n"
                  << "4: Stronger Goblin\n"
                  << "5: Strongest Goblin\n"
                  << "6: Abe Kongen\n"
                  << "7: Enhjoerning\n"
                  << "8: Drage\n"
                  << "9: Quit combat\n" + lineSeperator
                  << "Choose a monster to fight: ";
        getIntInput();

        if ((inputInt < 9) and (inputInt > 0)){ // Initiate combat with selected monster
            Combat combat;
            combat.battle(player, inputInt);
        }
        else if (inputInt == 9){ // Quit combat menu
            break;
        }
        else{
            std::cout << "Invallid input\n";
        }
        deathCount = 0; // Reset deathCount
        for (int i = 0; i < player.collection.size(); i++){
            if (player.collection[i].getHP() <= 0){ // Count dead allies
                deathCount++;
            }
        }
        if (deathCount == player.collection.size()){ // Quit combat menu if all allies are defeated
            std::cout << "No allied monsters left \nReturning to Main Menu" << std::endl;
            menuActive = false;
        }
        else {
            for (int i = 0; i < player.collection.size(); i++){ // Reset HP, dmg, and status effects for all allied monsters
                player.collection[i].resetAll();
                std::cout << "reset triggered" << player.collection[i].getDmg() << " " << player.collection[i].getHP();
            }
        }
    }
}

Menu::~Menu(){}
