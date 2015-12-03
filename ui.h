#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "person.h"
#include "data.h"

using namespace std;

struct UI {
    bool personChooser(vector<Person>& Per, Data& d);
    void personStarter(vector<Person>& Per, Data& d);
    void computerStarter(vector<Computers>& Comp, Data& d);
    void writer(vector<Person>& Per);
    void personInsert(vector<Person>& Per, Data& d);
    void searchByName(vector<Person>& Per, string name);
    bool NameChecker(string fname, string lname, vector<Person>& Per);
};

#endif // UI_H
