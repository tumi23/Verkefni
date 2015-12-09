#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class computer {
    string c_id;
    string name;
    string yearMade;
    string type;
    string made;
public:
    computer(string c_id_, string name_, string yearMade_, string type_, string made_);
    friend ostream& operator<<(ostream &out, const computer &x);
    string getname();
    string getyearMade();
    string gettype();
    string getmade();
    string getcid();
};

class Person {
    string p_id;
    string fname;
    string lname;
    string sex;
    string birth;
    string death;
public:
    Person(string per_id, string firstName, string lastName, string tSex, string tBirth, string tDeath);
    friend ostream& operator<<(ostream &out, const Person &x);
    string getfname();
    string getlname();
    string getsex();
    string getbirth();
    string getdeath();
    string getpid();
};
#endif // OBJECTS_H
