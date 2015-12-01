#include "data.h"
#include "person.h"
#include "ui.h"

using namespace std;

Person::Person(string firstname, string lastname, string tsex, string tbirth, string tdeath)
{
    fname = firstname;
    lname = lastname;
    sex = tsex;
    birth = tbirth;
    death = tdeath;
}

Person::testwriter()
{
    cout << "First Name: " << fname << "\nLast Name: " << lname << "\nSex: "<< sex << "\nBirth: "<< birth << "\nDeath: " << death << endl << endl;
}
