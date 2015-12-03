#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Computers
{
    public:
        Computers(string name_, string yearMade_, string type_, string made_);
        friend ostream& operator<<(ostream &out, const Computers &x);
        string getname();
        string getyearMade();
        string gettype();
        string getmade();
    private:
        string name;
        string yearMade;
        string type;
        string made;
};

#endif // COMPUTERS_H
