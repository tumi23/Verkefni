#include "ui.h"
#include <algorithm>


void UI::writer(vector<Person>& Per)
{
    int size = Per.size();
    for(int i = 0;i < size; i++)
    {
        Per[i].testwriter();
    }
}

bool UI::NameChecker(string fname, string lname,vector<Person>& Per)
{
    bool checker = true;
    string tfname, tlname;
    for(int i = 0;i < Per.size();i++)
    {
        tfname = Per[i].getfname();
        tlname = Per[i].getlname();
        if(tfname == fname && tlname == lname)
        {
            checker = false;
            cout << "You can't put someone who is already in the database, Please try again." << endl;
        }
        else
            continue;
    }
    return checker;
}

void UI::insert(vector<Person>& Per, Data& d)
{
    string fname, lname, sex, birth, death;
    bool breaker;
    breaker = false;
    while(breaker == false)
    {
        cout << "First name: ";
        cin >> fname;
        cout << "Last name: ";
        cin >> lname;
        breaker = NameChecker(fname,lname,Per);
    }
    breaker = false;
    while(breaker == false)
    {
        cout << "Sex: ";
        cin >> sex;
        if(sex == "M" || sex == "F" || sex == "m" || sex == "f")
        {
            breaker = true;
        }
        else
        {
            cout << "You can only be F(Female) or M(Male), please try again." << endl;
        }
    }
    breaker = false;
    while(breaker == false)
    {
        cout << "Date of birth: ";
        cin >> birth;
        cout << "Date of death: ";
        cin >> death;
        if(birth < death)
        {
            breaker = true;
        }
        else
        {
            cout << "You cant be dead before you're born, please try again." << endl;
        }
    }
    Per.push_back(Person(fname, lname, sex, birth, death));
    d.save(Per);
}

int GetChoice(int srtornot)//Gives information on what the user wants to do
{
    int input;
    if(srtornot == 0)
        cout << "(1)Add Person\n(2)Display Persons\n(3)Search by name\n(4)Sort\n!Anything else stops the program!\n" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n(1)First name\n(2)Last name\n(3)Sex\n(4)Date of birth\n(5)Date of death" << endl;
    cin >> input;
    return input;
}

void UI::Starter(vector<Person>& Per, Data& d)
{
    bool breaker = false;
    cout << "This is a Database to register and view\nFamous Computer people\n\n" << endl;
    while(breaker == false)
    {
        d.load(Per);
        breaker = Chooser(Per,d);
    }
}

bool UI::Chooser(vector<Person>& Per, Data& d)
{
    int srtornot = 0;
    bool breaker = false;
    string name;
    int input = GetChoice(srtornot);
    vector<string> firstname;
    vector<string> lastname;
    vector<string> sexes;
    vector<string> births;
    vector<string> deaths;
    int count = 0;
    switch (input) {
        case 1:
            insert(Per,d);
            break;
        case 2:
            writer(Per);
            break;
        case 3:
            cout << "Search By name/UI.SearchByName" << endl;
            cin >> name;
            searchByName(Per, name);
            break;
        case 4:
            srtornot = 1;
            input = GetChoice(srtornot);
            switch(input){
            case 1:
                cout << "Sort By First name" << endl;
                for(int i = 0; i < Per.size(); i++)
                {
                    firstname.push_back(Per[i].getfname());
                }
                sort(firstname.begin(), firstname.end());
                for(size_t i = 0; i < Per.size(); i++)
                {
                    for(size_t o = 0; o < Per.size(); o++)
                    {
                        if(Per[o].getfname() == firstname[i])
                            Per[o].testwriter();
                    }
                }
                break;
            case 2:
                cout << "Sort By Last name" << endl;
                for(int i = 0; i < Per.size(); i++)
                {
                    lastname.push_back(Per[i].getlname());
                }
                sort(lastname.begin(), lastname.end());
                for(size_t i = 0; i < Per.size(); i++)
                {
                    for(size_t o = 0; o < Per.size(); o++)
                    {
                        if(Per[o].getlname() == lastname[i])
                            Per[o].testwriter();
                    }
                }
                break;
            case 3:
                cout << "Sort By Sex" << endl;
                for(int i = 0; i < Per.size(); i++)
                {
                    sexes.push_back(Per[i].getsex());
                }
                sort(sexes.begin(), sexes.end());
                for(size_t i = 0; i < Per.size(); i++)
                {
                    for(size_t o = 0; o < Per.size(); o++)
                    {
                        if(Per[o].getsex() == sexes[i] && count != Per.size())
                        {
                            Per[o].testwriter();
                            count++;
                        }
                    }
                }
                break;
            case 4:
                cout << "Sort By Date of birth" << endl;
                for(int i = 0; i < Per.size(); i++)
                {
                    births.push_back(Per[i].getbirth());
                }
                sort(births.begin(), births.end());
                for(size_t i = 0; i < Per.size(); i++)
                {
                    for(size_t o = 0; o < Per.size(); o++)
                    {
                        if(Per[o].getbirth() == births[i] && count != Per.size())
                        {
                            Per[o].testwriter();
                            count++;
                        }
                    }
                }
                break;
            case 5:
                cout << "Sort By Date of death" << endl;
                for(int i = 0; i < Per.size(); i++)
                {
                    deaths.push_back(Per[i].getdeath());
                }
                sort(deaths.begin(), deaths.end());
                for(size_t i = 0; i < Per.size(); i++)
                {
                    for(size_t o = 0; o < Per.size(); o++)
                    {
                        if(Per[o].getdeath() == deaths[i] && count != Per.size())
                        {
                            Per[o].testwriter();
                            count++;
                        }
                    }
                }
                break;
            default:
                cout << "Wrong input!" << endl;
            }
            break;
        default:
            breaker = true;
  }
  return breaker;
}

void UI::searchByName(vector<Person>& Per, string name)
{
    string name1;
    int size = Per.size();
    size_t x;
    for(int i = 0; i < size; i++)
    {
        if(Per[i].getfname().find(name) != string::npos || Per[i].getlname().find(name) != string::npos)
        {
            Per[i].testwriter();
        }
    }
}
