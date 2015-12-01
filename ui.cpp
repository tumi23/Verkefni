#include "data.h"
#include "person.h"
#include "ui.h"
using namespace std;

void UI::writer(vector<Person>& Per)
{
    int size = Per.size();
    for(int i = 0;i < size; i++)
    {
        Per[i].testwriter();
    }
}

void UI::insert(vector<Person>& Per, Data& d)
{
    string fname, lname, sex, birth, death;
    cout << "First name: ";
    cin >> fname;
    cout << "Last name: ";
    cin >> lname;
    cout << "Sex: ";
    cin >> sex;
    cout << "Date of birth: ";
    cin >> birth;
    cout << "Date of death: ";
    cin >> death;
    Per.push_back(Person(fname, lname, sex, birth, death));
    d.save(Per);
}

int GetChoice(int srtornot)//Gives information on what the user wants to do
{
    int input;
    if(srtornot == 0)
        cout << "1)Add Person\n2)Display Persons\n3)Search by name\n4)Sort\n!Anything else stops the program!" << endl;
    else if(srtornot == 1)
        cout << "Sort by:\n1)First name\n2)Last name\n3)Sex\n4)Date of birth\n5)Date of death" << endl;
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
            cout << "Sort/UI.Sort";
            srtornot = 1;
            input = GetChoice(srtornot);
            switch(input){
            case 1:
                cout << "Sort By First name" << endl;
                break;
            case 2:
                cout << "Sort By Last name" << endl;
                break;
            case 3:
                cout << "Sort By Sex" << endl;
                break;
            case 4:
                cout << "Sort By Date of birth" << endl;
                break;
            case 5:
                cout << "Sort By Date of death" << endl;
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
    for(int i = 0; i < size; i++)
    {
        name1 = Per[i].getfname();
        if(name == name1)
        {
            Per[i].testwriter();
        }
    }
}
