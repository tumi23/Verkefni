#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"
#include "data.h"
using namespace std;

class UI
{
public:
    bool Chooser(vector<Person>& Per, Data& d);
    void Starter(vector<Person>& Per, Data& d);
    void writer(vector<Person>& Per);
    void insert(vector<Person>& Per, Data& d);
};

#endif // UI_H
