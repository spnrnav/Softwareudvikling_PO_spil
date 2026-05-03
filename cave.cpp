#include "cave.h"
#include "entityList.h"
#include "itemlist.h"
#include <ctime>

Cave::Cave(Character& player) {
    srand(time(NULL)); // resets seed to generate random number
    generateCave(player);
}

void Cave::generateCave(Character& player){
    int lvlEstimate = 0;
    EntityList enemyList;
    for (int i = 0; i < player.collection.size(); i++){ // Generate estimate of collective ally monster lvl
        for (int j = 0; j < enemyList.list.size(); j++){
            if (player.collection[i].getName() == enemyList.list[j].getName()){
                lvlEstimate += j+1;
            }
        }
    }
    int maxIdx = lvlEstimate-1;
    if (lvlEstimate > (enemyList.list.size()-1)){ // Set max enemy lvl
        maxIdx = (enemyList.list.size()-1);
    }
    int caveEstimate = 0;
    while (caveEstimate < lvlEstimate){
        int idx = generateRandomInt(maxIdx);
        hostiles.push_back(enemyList.list[idx]); // Add enemy to cave
        caveEstimate += idx+1; // Update cave lvl estimate
        if (caveEstimate < (maxIdx+1)){ // Regulate max enemy lvl
            maxIdx = lvlEstimate-caveEstimate;
        }
    }
    ItemList rewardList;
    reward = rewardList.list[generateRandomInt((rewardList.list.size()-1))]; // Generate random reward
}

int Cave::generateRandomInt(int highBound, int lowBound){
    return (rand() % highBound + lowBound);
}
