#include "person.h"

Person::Person(string firstname, string lastname, string tsex, string tbirth, string tdeath)
{
    fname = firstname;
    lname = lastname;
    sex = tsex;
    birth = tbirth;
    death = tdeath;
}

void Person::testwriter()
{
    cout << "First Name: " << fname << "\nLast Name: " << lname << "\nSex: "<< sex << "\nBirth: "<< birth << "\nDeath: " << death << endl << endl;
}

string Person::getfname()
{
    return fname;
}

string Person::getlname()
{
    return lname;
}

string Person::getsex()
{
    return sex;
}

string Person::getbirth()
{
    return birth;
}

string Person::getdeath()
{
    return death;
}
