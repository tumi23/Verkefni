#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <fstream>
#include <string>
#include <vector>

#include "objects.h"

using namespace std;

class Data {
public:
    void dbStarter();
    void personLoad(vector<Person>& p);
    void personSave(string fname,string lname, string sex, string birth, string death);
    void computerLoad(vector<Computers>& Comp);
    void computerSave(string name, string yearMade, string type, string doesItExist);
private:
    QSqlDatabase db;
};

#endif // UI_H
