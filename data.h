#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>

#include "objects.h"

using namespace std;

class Data {
public:
    void dbStarter();
    void personLoad(vector<Person>& p);
    void personSave(string fname,string lname, string sex, string birth, string death);
    void computerLoad(vector<computer>& Comp);
    void computerSave(string name, string yearMade, string type, string doesItExist);
    void idConnectSave(string c_id, string p_id);
    string creatorLoad(string c_id);
    string creatorLoad2(string p_id);
private:
    QSqlDatabase db;
};

#endif // UI_H
