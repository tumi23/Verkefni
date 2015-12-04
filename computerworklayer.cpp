#include "computerworklayer.h"

void computerWorkLayer::insert(vector<Computers>& Comp, Data& d)
{
    string name, yearMade, type, made;
    bool breaker;
    breaker = false;
    cout << "Name: ";
    cin >> name;
    cout << endl << "Year made: ";
    cin >> yearMade;
    cout << endl << "Type: ";
    cin >> type;
    cout << "Was it made? (Answer with yes or no)";
    cin >> made;
    Comp.push_back(Computers(name, yearMade, type, made));
//    d.computerSave(Comp);
}

void computerWorkLayer::searchByName(vector<Computers>& Comp)
{
    string name;
    cout << "Type in a name to search for: " << endl;
    cin >> name;
    int size = Comp.size();
    for(int i = 0; i < size; i++)
    {
        if(Comp[i].getname().find(name) != string::npos)
        {
            cout << Comp[i];
        }
    }
}

