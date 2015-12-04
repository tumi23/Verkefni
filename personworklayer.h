#ifndef DOMAINLAYER_H
#define DOMAINLAYER_H

#include "person.h"
#include "data.h"

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

#endif // DOMAINLAYER_H
