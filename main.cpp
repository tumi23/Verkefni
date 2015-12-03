#include "data.h"
#include "person.h"
#include "ui.h"

const string question = "Type 1 for computers and type 0 for People";

int main()
{
    vector<Person> Per;
    vector<Computers> Comp;
    Data d;
    UI uid;
    int x;
    cout << question;
    cin >> x;
    if(x == 0)
    {
        uid.personStarter(Per,d);
    }
    else if(x == 1)
    {
        uid.computerStarter(Comp,d);
    }
}
