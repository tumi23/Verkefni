#include "Computers.h"

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
    << "Type: " << x.type << endl << "Was it made?" << x.made;
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
