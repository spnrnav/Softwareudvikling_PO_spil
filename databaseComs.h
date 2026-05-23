#ifndef DATABASECOMS_H
#define DATABASECOMS_H
#include <string>
#include <vector>

class DatabaseComs
{
public:
    DatabaseComs(std::string n){fileName = n;}
    std::string getFileName(){return fileName;}
    void setFileName(std::string nNew){fileName = nNew;}
    ~DatabaseComs(){if(db){sqlite3_close}};
private:
    std::string fileName;
};

#endif // DATABASECOMS_H
