#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <string>
#include <vector>

#include "person.h"

using namespace std;

struct Data {
    void load(vector<Person>& p);
    void save(vector<Person>& p);
};

#endif // UI_H