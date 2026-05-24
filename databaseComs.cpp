#include "databaseComs.h"
#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include "entityList.h"
#include "itemlist.h"

DatabaseComs::DatabaseComs(std::string n) {
    fileName = n;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(n));
    std::cout << "Database opened\n";

    if (db.open()){
    	std::cout << "Database opened\n";
    }
    else{
	std::cout << "Database failed to open\n";
    }
    createTables();
}

DatabaseComs::~DatabaseComs(){
    if(db.isOpen()){
        db.close();
        std::cout << "Database closed\n";
    }
}

bool DatabaseComs::execute(std::string sql){
    QSqlQuery query;

    if (!query.exec(QString::fromStdString(sql))) {
        std::cerr << "SQL Error: "
                  << query.lastError().text().toStdString()
                  << std::endl;
        return false;
    }

    return true;
}

void DatabaseComs::createTables(){
    std::string karakter =
        "CREATE TABLE IF NOT EXISTS Character ("
        "characterId	INTEGER,"
        "name	TEXT,"
        "totalKillCount	INTEGER,"
        "itemMostUsed	TEXT,"
        "entityMostUsed	TEXT,"
        "PRIMARY KEY(characterId)"
        ");"; // 'karakter' used instead of 'character' to avoid potential keyword conflicts
    
    std::string entity =
        "CREATE TABLE IF NOT EXISTS Entity ("
        "entityId   INTEGER,"
        "characterId	INTEGER,"
        "entityIdx	INTEGER,"
        "PRIMARY KEY(entityId),"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";

    std::string entItem =
        "CREATE TABLE IF NOT EXISTS EntItem ("
        "itemIdx	INTEGER,"
        "entityId	INTEGER,"
        "itemKills	INTEGER,"
        "itemUses   INTEGER,"
        "FOREIGN KEY(entityId) REFERENCES Entity(entityId)"
        ");";
    
    std::string charItem =
        "CREATE TABLE IF NOT EXISTS CharItem ("
        "itemIdx	INTEGER,"
        "characterId	INTEGER,"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";
    
    execute(karakter);
    execute(entity);
    execute(entItem);
    execute(charItem);
}

void DatabaseComs::saveCharacter(Character& karakter){
    int i = 0;
}

void DatabaseComs::addSave(Character& karakter){
    //QSqlQuery query;
    std::string command;

    // Add character
    /*query.prepare("INSERT INTO Character "
                  "VALUES (?, ?, ?, ?, ?,)");
    int charIdx = 0; // must be the integer after the integer before
    query.addBindValue(charIdx); // characterId
    query.addBindValue(QString::fromStdString(karakter.getName())); // characterName
    query.addBindValue(karakter.getKillCount()); // totalKillCount
    query.addBindValue(QString::fromStdString(karakter.getMostUsedItem())); // itemMostUsed
    query.addBindValue(QString::fromStdString(karakter.getMostUsedEntity())); // entityMostUsed
    //qDebug << query.exec();
    query.exec();*/
    command = "INSERT INTO Character "
              "VALUES (";
    command += charIdx + ", " + karakter.getName() + ", " + karakter.getKillCount() + ", " + karakter.getMostUsedItem() + ", " + karakter.getMostUsedEntity() + ");";
    execute(command);

    // Add monsters
    EntityList el;
    ItemList il;
    for (int i = 0; i < karakter.collection.size(); ++i){
        //query.prepare("INSERT INTO Entity "
        //              "VALUES (?, ?, ?)");
        command = "INSERT INTO Entity "
                  "VALUES (";
        int entId = 0; // must be the integer after the integer before
        //query.addBindValue(entId); // entityId
        command += entId + ", ";
        //query.addBindValue(charIdx); // characterId
        command += charIdx + ", ";
        int entIdx;
        for (int j = 0; j < el.list.size(); ++j){
            if (karakter.collection[i].getName() == el.list[j].getName()){
                entIdx = j;
            }
        }
        //query.addBindValue(entIdx); // entityIdx
        command += entIdx + ");";
        //query.exec();
        execute(command);

        // Add monster items
        for (int j = 0; j < karakter.collection[i].getEquippedItems().size(); ++j){
            //query.prepare("INSERT INTO EntItem "
            //              "VALUES (?, ?, ?, ?)");
            command = "INSERT INTO EntItem "
                      "VALUES (";
            int iteIdx;
            for (int k = 0; k < il.list.size(); ++k){
                if (il.list[k].getName() == karakter.collection[i].getEquippedItems()[j].getName()){
                    iteIdx = k;
                }
            }
            //query.addBindValue(iteIdx); // itemIdx
            command += iteIdx + ", ";
            //query.addBindValue(entId); // entityId
            command += entId + ", ";
            //query.addBindValue(karakter.getItems()[i].getKills()); // itemKills
            command += karakter.getItems()[i].getKills() + ", ";
            //query.addBindValue(karakter.getItems()[i].getUses()); // itemUses
            command += karakter.getItems()[i].getUses() + ");";
            //query.exec();
            execute(command);
        }
    }
    
    // Add character items
    for (int i = 0; i < karakter.getItems().size(); ++i){
        //query.prepare("INSERT INTO CharItem "
        //              "VALUES (?, ?)");
        command = "INSERT INTO CharItem "
                  "VALUES (";
        int iteIdx;
        for (int j = 0; j < il.list.size(); ++j){
            if (il.list[j].getName() == karakter.getItems()[i].getName()){
                iteIdx = j;
            }
        }
        //query.addBindValue(iteIdx); // itemIdx
        command += iteIdx + ", ";
        //query.addBindValue(charIdx); // characterId
        command += charIdx + ");";
        //query.exec();
        execute(command);
    }
}

void DatabaseComs::updateSave(int charID, Character& karakter){
    QSqlQuery query;

    // Update character
    query.prepare("UPDATE Character "
                  "SET characterName = (?)"
                  "SET totalKillCount = (?)"
                  "SET itemMostUsed = (?)"
                  "SET entityMostUsed = (?)"
                  "WHERE characterId = (?)");
    query.addBindValue(QString::fromStdString(karakter.getName())); // characterName
    query.addBindValue(karakter.getKillCount()); // totalKillCount
    query.addBindValue(QString::fromStdString(karakter.getMostUsedItem())); // itemMostUsed
    query.addBindValue(QString::fromStdString(karakter.getMostUsedEntity())); // entityMostUsed
    query.addBindValue(charID); // characterId
    //qDebug << query.exec();
    query.exec();

    // Update monsters
    EntityList el;
    ItemList il;
    for (int i = 0; i < karakter.collection.size(); ++i){
        query.prepare("UPDATE Entity "
                      "SET entityIdx = (?)"
                      "WHERE characterId = (?)"
                      "AND WHERE entId = (?)");
        int entIdx;
        for (int j = 0; j < el.list.size(); ++j){
            if (karakter.collection[i].getName() == el.list[j].getName()){
                entIdx = j;
            }
        }
        query.addBindValue(entIdx); // entityIdx
        int entId = 0; // must be the integer after the integer before
        query.addBindValue(entId); // entityId
        query.addBindValue(charID); // characterId
        query.exec();

        // Update monster items
        for (int k = 0; k < karakter.collection[i].getEquippedItems().size(); ++k){
            query.prepare("UPDATE EntItem "
                          "SET itemIdx = (?)"
                          "SET itemKills = (?)"
                          "SET itemUses = (?)"
                          "WHERE entityId = (?)"
                          "AND WHERE characterId = (?)");
            int iteIdx;
            for (int j = 0; j < il.list.size(); ++j){
                if (il.list[j].getName() == karakter.collection[i].getEquippedItems()[k].getName()){
                    iteIdx = j;
                }
            }
            query.addBindValue(iteIdx); // itemIdx
            query.addBindValue(karakter.getItems()[i].getKills()); // itemKills
            query.addBindValue(karakter.getItems()[i].getUses()); // itemUses
            query.addBindValue(entId); // entityId
            query.addBindValue(charID); // characterId
            query.exec();
        }
    }
    
    // Add character items
    for (int i = 0; i < karakter.getItems().size(); ++i){
        query.prepare("UPDATE CharItem "
                      "SET itemIdx = (?)"
                      "WHERE characterId = (?)");
        int iteIdx;
        for (int j = 0; j < il.list.size(); ++j){
            if (il.list[j].getName() == karakter.getItems()[i].getName()){
                iteIdx = j;
            }
        }
        query.addBindValue(iteIdx); // itemIdx
        query.addBindValue(charID); // characterId
        query.exec();
    }
}
