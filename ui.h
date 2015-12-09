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
    void UIDbChoseLooper(vector<computer>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com);
    bool personChooser(vector<Person>& Per,vector<computer>& Comp, Data& d,PersonWorkLayer& pom);
    bool computerChooser(vector<computer>& Comp, Data& d,computerWorkLayer& com);
    void printMenu(string menu);
    char getInput();
};

#endif // UI_H
