#ifndef COMPUTERWORKLAYER_H
#define COMPUTERWORKLAYER_H

#include "data.h"
#include "Computers.h"
#include <algorithm>

struct computerWorkLayer {
    void insert(vector<Computers>& Comp, Data& d);
    void searchByName(vector<Computers>& Comp);
    void sortName(vector<Computers>& Comp);
    void sortYearMade(vector<Computers>& Comp);
    void sortType(vector<Computers>& Comp);
    void sortMade(vector<Computers>& Comp);
    void xd(int x);
};

#endif // COMPUTERWORKLAYER_H
