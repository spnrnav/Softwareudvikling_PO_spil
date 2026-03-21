#include "menu.h"
#include "character.h"
#include <iostream>

Menu::Menu() {}

void Menu::main(){
    std::string lineSeperator = "-----------------------------\n";
    int inputInt;
    std::string inputStr;
    bool gameActive = true;
    while (gameActive){
        std::cout << "----------Main menu----------\n"
                  << "1: New character\n"
                  << "2: Load character\n"
                  << "3: Quit game\n" + lineSeperator
                  << "Choose action: ";
        std::cin >> inputInt;
        std::cout << lineSeperator;

        if (inputInt == 1){ // New character
            std::cout << "Enter character name: ";
            std::cin.ignore();
            getline(std::cin, inputStr, '\n');
            Character player(inputStr);
            std::cout << "Character \"" + inputStr + "\" created\n";
        }
        else if (inputInt == 2){ // Load Character (implement later)
            std::cout << "action2\n";
        }
        else if (inputInt == 3){ // Quit game
            gameActive = false;
        }
        else {
            std::cout << "Invallid input\n";
        }
    }
}

Menu::~Menu(){}
