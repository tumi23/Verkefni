#include "data.h"
#include "objects.h"
#include "ui.h"
#include "worklayers.h"

int main()
{
    vector<Person> Per;
    vector<computer> Comp;
    Data d;
    UI uid;
    PersonWorkLayer pom;
    computerWorkLayer com;
    uid.startLoop(Comp,Per,d,pom,com);
}
