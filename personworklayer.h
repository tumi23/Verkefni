#ifndef DOMAINLAYER_H
#define DOMAINLAYER_H

#include "person.h"
#include "data.h"

struct PersonWorkLayer {
    void writer(vector<Person>& Per);
    void insert(Data& d, vector<Person>& Per);
    bool NameChecker(string fname, string lname, vector<Person>& Per);
    void searchByName(vector<Person>& Per);
};

#endif // DOMAINLAYER_H
