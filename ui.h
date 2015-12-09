#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "data.h"
#include "objects.h"
#include "worklayers.h"

using namespace std;

struct UI {
    void startLoop(vector<computer>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com);
    bool chooser(vector<Person>& Per,vector<computer>& Comp, Data& d,PersonWorkLayer& pom,computerWorkLayer& com);
    void printMenu(int menu);
    char getInput();
};

#endif // UI_H
