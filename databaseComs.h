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
    int execute(std::string);
    void createTables();
    void saveCharacter(Character&);
    void addSave(Character&);
    void updateSave(int, Character&);
    std::vector<Character> getCharacters();
    void assignItemsToChars(std::vector<Character>&, std::vector<int>);
    void assignEntities(std::vector<Character>&, std::vector<int>);
    void assignItemsToEnt(Entity&, int);
    int getMaxCharId();
    ~DatabaseComs();
private:
    std::string fileName;
    QSqlDatabase db;
};

#endif // DATABASECOMS_H
