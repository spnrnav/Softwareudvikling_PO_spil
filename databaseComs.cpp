#include "databaseComs.h"
#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

DatabaseComs::DatabaseComs(std::string n) {
    fileName = n;
    db = nullptr;
    
    int return_value = sqlite3_open(file.c_str(), &db); 
    
    if(return_value) {
        std::cerr << "Error, could not open database. " << sqlite3_errmsg(db) << std::endl;
    }   
    else {
        std::cout << "Opened database succesfully! " << std::endl;
    }
}

DatabaseComs::~DatabaseComs(){
    if(db){
        sqlite3_close(db);
        std::cout << "Database closed\n";
    }
}

bool DatabaseComs::execute(std::string sql){
    char* errMsg = nullptr;

    int return_code = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg); 

    if(return_code != SQLITE_OK) {
        std::cerr << " SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
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
        "CREATE TABLE Entity ("
        "entityIdx	INTEGER,"
        "characterId	INTEGER,"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";

    std::string item =
        "CREATE TABLE Entity ("
        "entityIdx	INTEGER,"
        "characterId	INTEGER,"
        "FOREIGN KEY(characterId) REFERENCES Character(characterId)"
        ");";
    
    execute(character);
    execute(entity);
    execute(item);
}
