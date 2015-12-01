#ifndef DATA_H
#define DATA_H
#include "person.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Data
{
public:
    void load(vector<Person>& p);
    void save(vector<Person>& p);
    Data();
private:

};

#endif // DATA_H
