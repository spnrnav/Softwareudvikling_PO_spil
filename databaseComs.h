#ifndef DATABASECOMS_H
#define DATABASECOMS_H
#include <string>
#include <vector>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include "character.h"


class DatabaseComs
{
public:
    DatabaseComs(std::string n = "database.db");
    std::string getFileName(){return fileName;}
    void setFileName(std::string nNew){fileName = nNew;}
    bool execute(std::string);
    void createTables();
    void saveCharacter(Character&);
    void addSave(Character&);
    void updateSave(int, Character&);
    std::vector<Character> getCharacters();
    std::vector<Character> assignItemsToChars(std::vector<Character&>, std::vector<int>);
    std::vector<Character> assignEntities(std::vector<Character&>, std::vector<int>);
    std::vector<Entity> assignItemsToEnt(std::vector<Entity&>, std::vector<int>);
    int getMaxCharId();
    ~DatabaseComs();
private:
    std::string fileName;
    QSqlDatabase db;
};

#endif // DATABASECOMS_H
