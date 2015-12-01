#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "person.h"

using namespace std;

struct Data {
    void load(vector<Person>& p);
    void save(vector<Person>& p);
    Data();
};

#endif // UI_H