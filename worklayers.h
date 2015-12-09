#ifndef WORKLAYERS_H
#define WORKLAYERS_H

#include "data.h"
#include "objects.h"
#include <algorithm>

struct computerWorkLayer {
    void insert(vector<computer>& Comp, Data& d);
    void searchByName(vector<computer>& Comp, Data& d);
    void sortName(vector<computer>& Comp, Data& d);
    void sortYearMade(vector<computer>& Comp, Data& d);
    void sortType(vector<computer>& Comp, Data& d);
    void sortMade(vector<computer>& Comp, Data& d);
    void xd(int x);
};

struct PersonWorkLayer {
    void insert(Data& d, vector<Person>& Per,vector<computer>& Comp);
    void modifyConnection(Data& d, vector<Person>& Per,vector<computer>& Comp);
    bool NameChecker(string fname, string lname, vector<Person>& Per);
    void searchByName(vector<Person>& Per,Data& d);
    void sortName(vector<Person>& Per,Data& d);
    void sortLastName(vector<Person>& Per,Data& d);
    void sortSex(vector<Person>& Per,Data& d);
    void sortBirth(vector<Person>& Per,Data& d);
    void sortDeath(vector<Person>& Per,Data& d);
};

#endif // WORKLAYERS_H
