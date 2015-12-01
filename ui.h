#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>

#include "person.h"
#include "data.h"

using namespace std;

struct UI {
    bool Chooser(vector<Person>& Per, Data& d);
    void Starter(vector<Person>& Per, Data& d);
    void writer(vector<Person>& Per);
    void insert(vector<Person>& Per, Data& d);
    void searchByName(vector<Person>& Per, string name);
};

#endif // UI_H
