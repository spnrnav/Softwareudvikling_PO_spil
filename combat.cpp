#include "combat.h"
#include <ctime>
#include <iostream>
//#include "enemyList.h"

Combat::Combat() {
    srand(time(NULL)); // resets seed to generate random number
}

int Combat::generateRandomInt(int highBound, int lowBound){
    return (rand() % (highBound - lowBound) + lowBound);
}

void Combat::getIntInput(){
    std::cin >> inputInt;
    std::cout << lineSeperator;
}

void Combat::getStrInput(){
    std::cin.ignore();
    getline(std::cin, inputStr, '\n');
    std::cout << lineSeperator;
    std::cout << "\"" + inputStr + "\"";
}

void Combat::getChaInput(){
    std::cin >> inputCha;
    std::cout << lineSeperator;
}

void Combat::applyStatus(Entity& caster, Entity& opponent, std::string status){
    if ((status == "Strength") or (status == "Regenerate") or (status == "block")){
        caster.addStatus(status);
    }
    else{
        opponent.addStatus(status);
    }
}

void Combat::resolveStatus(Entity& creature){
    std::vector<std::string> statusList = creature.getStatusList();
    for (int i = 0; i < statusList.size(); i++){
        if (statusList[i] == "Regenerate"){
            creature.heal(2); // heals 2 (a scale could be implemented later) (can stack)
        }
        else if (statusList[i] == "Block"){
            creature.addBlock(1); // blocks up to 1 incoming dmg, when the creature wold take damage next (can stack)
        }
        else if (statusList[i] == "Poison"){
            creature.dealDmg(1); // deal 1 dmg each turn (can stack)
        }
        else if (statusList[i] == "Explode"){
            creature.dealDmg(10); // deal 10 dmg (is removed after use)
            creature.removeStatus(i);
        }
        else if (statusList[i] == "Strength"){
            creature.addStrength(1); // adds 1 dmg to next attack (can stack)
        }
    }
}

void Combat::enemyTurn(Character& player, Entity& enemy, int allyIdx){
    resolveStatus(enemy);
    if (enemy.getHP() > 0){ // Check enemy HP
        if (enemy.getEquippedItems().empty()){
            std::cout << "Enemy " + enemy.getName() + " attacks\n";
            player.collection[allyIdx].dealDmg(enemy.getDmg()); // deal damage to ally
        }
        else {
            if (generateRandomInt() < 50){
                std::cout << "Enemy " + enemy.getName() + " attacks\n";
                player.collection[allyIdx].dealDmg(enemy.getDmg()); // deal damage to ally
            }
            else {
                Item use = enemy.getEquippedItems()[generateRandomInt((enemy.getEquippedItems().size()-1))]; // Choose item
                std::cout << "Enemy " + enemy.getName() + " uses a " + use.getName() + "\n";
                applyStatus(enemy, player.collection[allyIdx], use.getStatus()); // Apply status;
            }
        }
    }
    if (player.collection[allyIdx].getHP() <= 0){ // check ally HP
        std::cout << "Ally " + player.collection[allyIdx].getName() + " defeated\n";
    }
}

void Combat::allyTurn(Character& player, Entity& enemy, int allyIdx){
    resolveStatus(player.collection[allyIdx]);
    if (player.collection[allyIdx].getHP() > 0){
        if (!(player.collection[allyIdx].getEquippedItems().empty())){ // Allow for choice of action, if it is relevent
            std::cout << "1: Attack \n2: Use item \nChoose action: ";
            getIntInput();
        }
        else { // Defaults to attack
            inputInt = 1;
        }

        if (inputInt == 2){ // Use item
            for (int i = 0; i < player.collection[allyIdx].getEquippedItems().size(); i++){
                std::cout << (i+1) << ": " << player.collection[allyIdx].getEquippedItems()[i].getName() << "\n";
                std::cout << "Choose item to use: ";
                getIntInput();
                std::cout << "Allied " + player.collection[allyIdx].getName() + " uses a " + player.collection[allyIdx].getEquippedItems()[inputInt-1].getName() + "\n";
                applyStatus(player.collection[allyIdx],enemy,player.collection[allyIdx].getEquippedItems()[inputInt-1].getStatus());
                player.collection[allyIdx].getEquippedItems()[inputInt-1].addUse(); // add use to item
            }
        }
        else { // Defaults to regular attack
            std::cout << "Allied " + player.collection[allyIdx].getName() + " attacks\n";
            enemy.dealDmg(player.collection[allyIdx].getDmg()); // deal damage to enemy
        }
    }
    if (enemy.getHP() <= 0){ // Enemy HP<=0
        std::cout << "Enemy " <<  enemy.getName() << " defeated\n";
        std::cout << "Capture enemy? (y/n): ";
        getChaInput();
        if (inputCha == 'y'){
            if (player.collectionLimit() == false){
                for (int j = 0; j < player.collection.size(); j++){ // Display names of all allies
                    std::cout << j+1 << ": " << player.collection[j].getName() << " (Hp: " << player.collection[j].getBaseHP() << ", Dmg: " << player.collection[j].getBaseDmg() << ")" << std::endl;
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
        player.collection[i].addUses();
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
            player.addKill();
            break;
        }
    }
}

Combat::~Combat(){}
