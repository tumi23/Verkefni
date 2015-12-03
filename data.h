#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <string>
#include <vector>

#include "person.h"
#include "Computers.h"

using namespace std;

struct Data {
    void personLoad(vector<Person>& p);
    void personSave(vector<Person>& p);
    void computerLoad(vector<Computers>& Comp);
    void computerSave(vector<Computers>& Comp);
};

#endif // UI_H
