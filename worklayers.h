#ifndef WORKLAYERS_H
#define WORKLAYERS_H

#include "data.h"
#include "objects.h"
#include <algorithm>

struct computerWorkLayer {
    void insert(vector<computer>& Comp, Data& d);
    void searchByName(vector<computer>& Comp);
    void sortName(vector<computer>& Comp);
    void sortYearMade(vector<computer>& Comp);
    void sortType(vector<computer>& Comp);
    void sortMade(vector<computer>& Comp);
    void xd(int x);
};

struct PersonWorkLayer {
    void insert(Data& d, vector<Person>& Per);
    bool NameChecker(string fname, string lname, vector<Person>& Per);
    void searchByName(vector<Person>& Per);
    void sortName(vector<Person>& Per);
    void sortLastName(vector<Person>& Per);
    void sortSex(vector<Person>& Per);
    void sortBirth(vector<Person>& Per);
    void sortDeath(vector<Person>& Per);
};

#endif // WORKLAYERS_H
