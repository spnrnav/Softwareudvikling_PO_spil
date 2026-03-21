#include "menu.h"
#include "EnemyList.h"

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

void Menu::sub(){
    bool menuActive = true;
    while (menuActive){
        std::cout << "--------Adventure menu-------\n"
                  << "1: Fight monster\n"
                  << "2: Quit adventure\n" + lineSeperator
                  << "Choose action: ";
        getIntInput();

        if (inputInt == 1){ // Fight monster

        }
        else if (inputInt == 2){ // Quit sub menu
            menuActive = false;
        }
        else{
            std::cout << "Invallid input\n";
        }
    }
}

void Menu::combat(Entity enemy){
    bool menuActive = true;
    while (menuActive){
        std::cout << "---------Combat menu---------\n"
                  << "1: Hest\n"
                  << "2: Weak Goblin\n"
                  << "3: Strong Goblin\n"
                  << "4: Stronger Goblin\n"
                  << "5: Strongest Goblin\n"
                  << "6: Abe Kongen\n"
                  << "7: Enhjørning\n"
                  << "8: Drage\n"
                  << "9: Quit combat\n" + lineSeperator
                  << "Choose a monster to fight: ";
        getIntInput();

        if ((inputInt < 9) && (inputInt > 0)){ // Initiate combat with selected monster
            //combatClass
        }
        else if (inputInt == 9){ // Quit combat menu
            menuActive = false;
        }
        else{
            std::cout << "Invallid input\n";
        }
    }
}

Menu::~Menu(){}
