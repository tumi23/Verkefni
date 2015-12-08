#include "data.h"
#include "objects.h"
#include "ui.h"
#include "worklayers.h"

int main()
{
    vector<Person> Per;
    vector<Computers> Comp;
    Data d;
    UI uid;
    PersonWorkLayer pom;
    computerWorkLayer com;
    uid.UIDbChoseLooper(Comp,Per,d,pom,com);
}
