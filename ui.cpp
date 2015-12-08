#include "ui.h"
#include <algorithm>

void UI::UIDbChoseLooper(vector<computer>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com)
{
    int input;
    bool breaker = false;
    d.dbStarter();
    while(breaker == false)
    {
        cout << "(1)Person Database\n(2)Computer Database\n!Anything Else Quits!" << endl;
        cin >> input;
        switch(input){
            case 1:
                personStarter(Per,d,pom);
                break;
            case 2:
                computerStarter(Comp,d,com);
                break;
            default:
                breaker = true;
        }
    }
}

void UI::personStarter(vector<Person>& Per, Data& d, PersonWorkLayer& pom)
{
    bool breaker = false;
    cout << "\nThis is a Database to register\nand view Famous Computer people\n" << endl;
    while(breaker == false)
    {
        d.personLoad(Per);
        breaker = personChooser(Per,d,pom);
    }
}

int UI::GetPersonChoice(int srtornot)//Gives information on what the user wants to do
{
    int input;
    if(srtornot == 0)
        cout << "(1)Add Person\n(2)Display Persons\n(3)Search by name\n(4)Sort\n!Anything else returns you back to choose a database!\n" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n(1)First name\n(2)Last name\n(3)Sex\n(4)Date of birth\n(5)Date of death" << endl;
    cin >> input;
    return input;
}

bool UI::personChooser(vector<Person>& Per, Data& d,PersonWorkLayer& pom)
{
    int srtornot = 0;
    bool breaker = false;
    string name;
    int input = GetPersonChoice(srtornot);
    switch (input) {
        case 1:
            pom.insert(d,Per);
            break;
        case 2:
            for(size_t i = 0; i < Per.size(); i++)
            {
                cout << Per[i];
            }
            break;
        case 3:
            pom.searchByName(Per);
            break;
        case 4:
            srtornot = 1;
            input = GetPersonChoice(srtornot);
            switch(input){
            case 1:
                pom.sortName(Per);
                break;
            case 2:
                pom.sortLastName(Per);
                break;
            case 3:
                pom.sortSex(Per);
                break;
            case 4:
                pom.sortBirth(Per);
                break;
            case 5:
                pom.sortDeath(Per);
                break;
            default:
                cout << "Wrong input!" << endl;
            }
        default:
            breaker = true;
        }
  return breaker;
}

void UI::computerStarter(vector<computer>& Comp, Data& d,computerWorkLayer& com)
{
    bool breaker = false;
    cout << "\nThis is a Database to register\nand view Famous computer\n" << endl;
    while(breaker == false)
    {
        d.computerLoad(Comp);
        breaker = computerChooser(Comp,d,com);
    }
}

int UI::GetComputerChoice(int srtornot)
{
    int input;
    if(srtornot == 0)
        cout << "(1)Add Computer\n(2)Display computer\n(3)Search by name\n(4)sort\n!Anything else returns you back to choose a database!\n" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n (1)Name\n(2)Year made\n(3)Type\n(4)If it was made or not\n" << endl;
    cin >> input;
    return input;
}

bool UI::computerChooser(vector<computer>& Comp, Data& d,computerWorkLayer& com)
{
    int srtornot = 0;
    bool breaker = false;
    string name1;
    int input = GetComputerChoice(srtornot);
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
