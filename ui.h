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
#include "computerworklayer.h"

using namespace std;

struct UI {
    void UIDbChoseLooper(vector<Computers>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com);
    void personStarter(vector<Person>& Per, Data& d,PersonWorkLayer& pom);
    bool personChooser(vector<Person>& Per, Data& d,PersonWorkLayer& pom);
    int GetPersonChoice(int srtornot);
    void computerStarter(vector<Computers>& Comp, Data& d,computerWorkLayer& com);
    bool computerChooser(vector<Computers>& Comp, Data& d,computerWorkLayer& com);
    int GetComputerChoice(int srtornot);
};

#endif // UI_H
