#include "ui.h"
#include <algorithm>

int GetPersonChoice(int srtornot)//Gives information on what the user wants to do
{
    int input;
    if(srtornot == 0)
        cout << "(1)Add Person\n(2)Display Persons\n(3)Search by name\n(4)Sort\n!Anything else stops the program!\n" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n(1)First name\n(2)Last name\n(3)Sex\n(4)Date of birth\n(5)Date of death" << endl;
    cin >> input;
    return input;
}

int GetComputerChoice(int srtornot)
{
    int input;
    if(srtornot == 0)
        cout << "(1)Add Computer\n(2)Display Computers\n(3)Search by name\n(4)sort\n!Anything else stops the program!\n" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n (1)Name\n(2)Year made\n(3)Type\n(4)If it was made or not\n" << endl;
    cin >> input;
    return input;
}

void UI::personStarter(vector<Person>& Per, Data& d, PersonWorkLayer& dom)
{
    bool breaker = false;
    cout << "This is a Database to register and view\nFamous Computer people\n\n" << endl;
    while(breaker == false)
    {
        d.personLoad(Per);
        breaker = personChooser(Per,d,dom);
    }
}

void computerStarter(vector<Computers>& Comp, Data& d,computerWorkLayer& com)
{
    bool breaker = false;
    cout << "This is a Database to register and view Computers" << endl;
    while(breaker == false)
    {
//        d.computerLoad(Comp);
//        breaker = computerChooser(Comp,d,com);
    }
}

bool UI::personChooser(vector<Person>& Per, Data& d,PersonWorkLayer& dom)
{
    int srtornot = 0;
    bool breaker = false;
    string name;
    int input = GetPersonChoice(srtornot);
    vector<string> firstname;
    vector<string> lastname;
    vector<string> sexes;
    vector<string> births;
    vector<string> deaths;
    int count = 0;
    switch (input) {
        case 1:
            dom.insert(d,Per);
            break;
        case 2:
            for(size_t i = 0; i < Per.size(); i++)
            {
                cout << Per[i];
            }
            break;
        case 3:
            dom.searchByName(Per);
            break;
        case 4:
            srtornot = 1;
            input = GetPersonChoice(srtornot);
            switch(input){
            case 1:
                cout << "Sort By First name" << endl;
                dom.sortName(Per);
                break;
            case 2:
                cout << "Sort By Last name" << endl;
                dom.sortLastName(Per);
                break;
            case 3:
                cout << "Sort By Sex" << endl;
                dom.sortSex(Per);
                break;
            case 4:
                cout << "Sort By Date of birth" << endl;
                dom.sortBirth(Per);
                break;
            case 5:
                cout << "Sort By Date of death" << endl;
                dom.sortDeath(Per);
            break;
        default:
            breaker = true;
  }
  return breaker;
}

bool UI::computerChooser(vector<Computers>& Comp, Data& d,computerWorkLayer& com)
{
    int srtornot = 0;
    bool breaker = false;
    string name1;
    int input = GetComputerChoice(srtornot);
    vector<string> name;
    vector<string> yearMade;
    vector<string> type;
    vector<string> made;
    int count = 0;
    switch (input) {
        case 1:
            com.insert(Comp, d);
            break;
        case 2:
            for(size_t i = 0; i < Comp.size(); i++)
            {
                cout << Comp[i];
            }
            break;
        case 3:
            com.searchByName(Comp);
            break;
        case 4:
            srtornot = 1;
            input = GetComputerChoice(srtornot);
            switch(input){
            case 1:
                com.sortName(Comp);
                break;
            case 2:
                cout << "Sort By Year Made" << endl;
                com.sortYearMade(Comp);
                break;
            case 3:
                cout << "Sort By Type" << endl;
                com.sortType(Comp);
                break;
            case 4:
                cout << "Sort By if it has been made or not" << endl;
                com.sortMade(Comp);
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
