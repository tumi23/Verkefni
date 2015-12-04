#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "person.h"
#include "data.h"
#include "Computers.h"
#include "personworklayer.h"

using namespace std;

struct UI {
    bool personChooser(vector<Person>& Per, Data& d,PersonWorkLayer& dom);
    bool computerChooser(vector<Computers>& Comp, Data& d);
    void personStarter(vector<Person>& Per, Data& d,PersonWorkLayer& dom);
    void computerStarter(vector<Computers>& Comp, Data& d);
    void writer(vector<Person>& Per);
    void personInsert(vector<Person>& Per, Data& d);
    void computerInsert(vector<Computers>& Comp, Data& d);
    void personsearchByName(vector<Person>& Per, string name);
    void computersearchByName(vector<Computers>& Comp, string name);
    bool NameChecker(string fname, string lname, vector<Person>& Per);
};

#endif // UI_H
