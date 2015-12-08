#include "data.h"
#include "person.h"
#include "ui.h"
#include "personworklayer.h"
#include "computerworklayer.h"
#include "Computers.h"

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
