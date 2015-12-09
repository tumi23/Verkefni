#include "objects.h"
/*
Hid agalega objects fallid sem er sma vont ad horfa a enn virkar thratt fyrir thad
thad ad mestu leiti ser um allt sem tengist person og computure structure-inum
medal annars overload << operatorinn og skila af ser tilteknum stokum sem
mismunandi partar af forritun thurfa t.d. fyrsta nafn ur person vectornum
eda eitthvad i tha attina.
*/

computer::computer(string c_id_, string name_, string yearMade_, string type_, string made_)
{
    c_id = c_id_;
    name = name_;
    yearMade = yearMade_;
    type = type_;
    made = made_;
}

ostream& operator<<(ostream &out, const computer &x)
{
    out << "\nName: " << x.name << "\nYear invented: " << x.yearMade << "\nType of Computer: " << x.type << "\nDoes it exist: " << x.made << endl;
    return out;
}

string computer::getname()
{
    return name;
}

string computer::getyearMade()
{
    return yearMade;
}

string computer::gettype()
{
    return type;
}

string computer::getmade()
{
    return made;
}

string computer::getcid()
{
    return c_id;
}

Person::Person(string per_id, string firstName, string lastName, string tSex, string tBirth, string tDeath)
{
    p_id = per_id;
    fname = firstName;
    lname = lastName;
    sex = tSex;
    birth = tBirth;
    death = tDeath;
}

ostream& operator<<(ostream &out, const Person &x)
{
    out << "\nFirst Name: "<< x.fname << "\nLast Name: " << x.lname << "\nSex: " << x.sex << "\nYear Of Birth: " << x.birth << "\nYear Of Death: " << x.death << endl;
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

string Person::getpid()
{
    return p_id;
}
