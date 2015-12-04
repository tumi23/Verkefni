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
    bool personChooser(vector<Person>& Per, Data& d,PersonWorkLayer& pom);
    bool computerChooser(vector<Computers>& Comp, Data& d,computerWorkLayer& com);
    void personStarter(vector<Person>& Per, Data& d,PersonWorkLayer& pom);
    void computerStarter(vector<Computers>& Comp, Data& d,computerWorkLayer& com);
};

#endif // UI_H
