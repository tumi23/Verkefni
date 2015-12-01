#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Person {
    string fname;
    string lname;
    string sex;
    string birth;
    string death;
public:
    Person(string firstname, string lastname, string tsex, string tbirth, string tdeath);
    void testwriter();
    string getfname();
    string getlname();
    string getsex();
    string getbirth();
    string getdeath();
};
