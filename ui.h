#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"
using namespace std;

class UI
{
public:
    bool Chooser(vector<Person>& Per);
    void Starter(vector<Person>& Per);
};

#endif // UI_H
