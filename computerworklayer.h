#ifndef COMPUTERWORKLAYER_H
#define COMPUTERWORKLAYER_H

#include "person.h"
#include "data.h"

struct computerWorkLayer {
    void insert(vector<Computers>& Comp, Data& d);
    void searchByName(vector<Computers>& Comp);
};

#endif // COMPUTERWORKLAYER_H
