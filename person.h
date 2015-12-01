#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Person
{
public:
    Person(string firstname, string lastname, string tsex, string tbirth, string tdeath);
    testwriter();
    string getfname();
    string getlname();
    string getsex();
    string getbirth();
    string getdeath();
private:
    string fname;
    string lname;
    string sex;
    string birth;
    string death;
};

#endif // PERSON_H
