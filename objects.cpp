#include "objects.h"

Computers::Computers(string name_, string yearMade_, string type_, string made_)
{
    name = name_;
    yearMade = yearMade_;
    type = type_;
    made = made_;
}

ostream& operator<<(ostream &out, const Computers &x)
{
    out << "Name: " << x.name << endl << "Year made: " << x.yearMade << endl
    << "Type: " << x.type << endl << "Was it made?: " << x.made << endl << endl;
    return out;
}

string Computers::getname()
{
    return name;
}

string Computers::getyearMade()
{
    return yearMade;
}

string Computers::gettype()
{
    return type;
}

string Computers::getmade()
{
    return made;
}

Person::Person(string firstName, string lastName, string tSex, string tBirth, string tDeath)
{
    fname = firstName;
    lname = lastName;
    sex = tSex;
    birth = tBirth;
    death = tDeath;
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
