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
                  << "2: Quit adventure\n" + lineSeperator
                  << "Choose action: ";
        getIntInput();

        if (inputInt == 1){ // Fight monster
            combat(character);
        }
        else if (inputInt == 2){ // Quit sub menu
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
