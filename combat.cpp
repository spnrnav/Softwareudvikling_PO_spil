#include "combat.h"
#include <ctime>
#include <iostream>
//#include "enemyList.h"

Combat::Combat() {
    srand(time(NULL)); // resets seed to generate random number
}

int Combat::generateRandomInt(int highBound, int lowBound){
    return (rand() % highBound + lowBound);
}

void Combat::getIntInput(){
    std::cin >> inputInt;
    std::cout << lineSeperator;
}

void Combat::getStrInput(){
    std::cin.ignore();
    getline(std::cin, inputStr, '\n');
    std::cout << lineSeperator;
}

void Combat::enemyTurn(Character& player, Entity& enemy, int allyIdx){
    if (enemy.getHP() > 0){ // Check enemy HP
        std::cout << "Enemy " + enemy.getName() + " attacks\n";
        player.collection[allyIdx].dealDmg(enemy.getDmg()); // deal damage to ally
    }
    if (player.collection[allyIdx].getHP() <= 0){ // check ally HP
        std::cout << "Ally " + player.collection[allyIdx].getName() + " defeated\n";
    }
}

void Combat::allyTurn(Character& player, Entity& enemy, int allyIdx){
    if (player.collection[allyIdx].getHP() > 0){
        std::cout << "Allied " + player.collection[allyIdx].getName() + " attacks\n";
        enemy.dealDmg(player.collection[allyIdx].getDmg()); // deal damage to enemy
    }
    if (enemy.getHP() <= 0){ // Enemy HP<0
        std::cout << "Enemy " <<  enemy.getName() << " defeated\n";
        std::cout << "Capture enemy? (y/n): ";
        getStrInput();
        if (inputStr == "y"){
            if (player.collectionLimit() == false){
                for (int j = 0; j < player.collection.size(); j++){ // Display names of all allies
                    std::cout << j+1 << ": " << player.collection[j].getName() << " (Hp: " << player.collection[j].getHP() << ", Dmg: " << player.collection[j].getDmg() << ")" << std::endl;
                }
            }
            player.addMonster(monster.list[mMonsterIdx-1]); // run addMonster() function
        }
    }
}

void Combat::battle(Character& player, int monsterIdx){
    mMonsterIdx = monsterIdx;
    Entity enemy = monster.list[monsterIdx-1];
    int turnOrder = generateRandomInt();
    for (int i = 0; i < player.collection.size(); i++){ // Run through all player monsters
        while ((player.collection[i].getHP() > 0) and (enemy.getHP() > 0)){ // check health of ally and enemy
            //std::cout << "ally " << i << std::endl;
            //turnOrder = generateRandomInt();
            if (turnOrder < 50){ // turn priority (ally first)
                allyTurn(player, enemy, i);
                enemyTurn(player, enemy, i);
            }
            else{ // turn priority (enemy first)
                enemyTurn(player, enemy, i);
                allyTurn(player, enemy, i);
            }
        }
        if (enemy.getHP() <= 0){
            break;
        }
    }
}

Combat::~Combat(){}
