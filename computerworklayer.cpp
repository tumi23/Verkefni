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

void computerWorkLayer::sortName(vector<Computers>& Comp)
{
    vector<string> name;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        name.push_back(Comp[i].getname());
    }
    sort(name.begin(), name.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getname() == name[i])
                cout << Comp[o];
        }
    }
}

void computerWorkLayer::sortYearMade(vector<Computers>& Comp)
{
    vector<string> yearMade;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        yearMade.push_back(Comp[i].getyearMade());
    }
    sort(yearMade.begin(), yearMade.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getyearMade() == yearMade[i])
                cout << Comp[o];
        }
    }
}

void computerWorkLayer::sortType(vector<Computers>& Comp)
{
    vector<string> type;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        type.push_back(Comp[i].gettype());
    }
    sort(type.begin(), type.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].gettype() == type[i] && count != Comp.size())
            {
                cout << Comp[o];
                    count++;
            }
        }
    }
}

void computerWorkLayer::sortMade(vector<Computers>& Comp)
{
    vector<string> made;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        made.push_back(Comp[i].getmade());
    }
    sort(made.begin(), made.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getmade() == made[i] && count != Comp.size())
            {
                cout << Comp[o];
                    count++;
            }
        }
    }
}
