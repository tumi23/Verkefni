#ifndef WORKLAYERS_H
#define WORKLAYERS_H

#include "data.h"
#include "objects.h"
#include <algorithm>

struct computerWorkLayer {
    void insert(vector<Computers>& Comp, Data& d);
    void searchByName(vector<Computers>& Comp);
    void sortName(vector<Computers>& Comp);
    void sortYearMade(vector<Computers>& Comp);
    void sortType(vector<Computers>& Comp);
    void sortMade(vector<Computers>& Comp);
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
