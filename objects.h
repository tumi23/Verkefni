#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Computers
{
    string name;
    string yearMade;
    string type;
    string made;
public:
    Computers(string name_, string yearMade_, string type_, string made_);
    friend ostream& operator<<(ostream &out, const Computers &x);
    string getname();
    string getyearMade();
    string gettype();
    string getmade();
};

class Person {
    string fname;
    string lname;
    string sex;
    string birth;
    string death;
public:
    Person(string firstName, string lastName, string tSex, string tBirth, string tDeath);
    friend ostream& operator<<(ostream &out, const Person &x);
    string getfname();
    string getlname();
    string getsex();
    string getbirth();
    string getdeath();
};

#endif // OBJECTS_H