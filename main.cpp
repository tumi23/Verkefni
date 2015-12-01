#include <iostream>
#include <vector>
#include "data.h"
#include "person.h"
#include "ui.h"

using namespace std;

int main()
{
    vector<Person> Per;
    Data d;
    UI uid;
    uid.Starter(Per,d);
}
