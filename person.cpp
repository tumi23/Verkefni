#include "person.h"

Person::Person(string firstname, string lastname, string tsex, string tbirth, string tdeath)
{
    fname = firstname;
    lname = lastname;
    sex = tsex;
    birth = tbirth;
    death = tdeath;
}

ostream& operator<<(ostream &out, const Person &x)
{
    out << "First Name: " << x.fname << "\nLast Name: " << x.lname << "\nSex: "<< x.sex << "\nBirth: "<< x.birth << "\nDeath: " << x.death << endl << endl;
    return out;
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
