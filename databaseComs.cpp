#include "databaseComs.h"
#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

DatabaseComs::DatabaseComs(std::string n) {
    fileName = n;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    std::cout << "Database opened\n";
    
    if (db.open()){
    	std::cout << "Database opened\n";
    }
    else{
	std::cout << "Database failed to open\n";
    }
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
    std::string character =
        "CREATE TABLE IF NOT EXISTS character ("
        "characterId	INTEGER,"
        "name	TEXT,"
        "totalKillCount	INTEGER,"
        "itemMostUsed	INTEGER,"
        "entityMostUsed	INTEGER,"
        "PRIMARY KEY(characterId),"
        "FOREIGN KEY(entityMostUsed) REFERENCES Entity(entityIdx),"
        "FOREIGN KEY(itemMostUsed) REFERENCES Item(itemIdx)"
        ");";
    
    std::string entity =
        "CREATE TABLE IF NOT EXISTS Entity ("
        "entityIdx	INTEGER,"
        "characterId	INTEGER,"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";

    std::string item =
        "CREATE TABLE IF NOT EXISTS ITEM ("
        "itemIdx	INTEGER,"
        "characterId	INTEGER,"
        "itemKills	INTEGER,"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";
    
    execute(character);
    execute(entity);
    execute(item);
}
