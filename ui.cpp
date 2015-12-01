#include "data.h"
#include "person.h"
#include "ui.h"
using namespace std;

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

void UI::Starter(vector<Person>& Per)
{
    bool breaker = false;
    cout << "This is a Database to register and view\nFamous Computer people\n\n" << endl;
    while(breaker == false)
    {
        breaker = Chooser(Per);
    }
}

bool UI::Chooser(vector<Person>& Per)
{
    int srtornot = 0;
    int size;
    bool breaker = false;
    int input = GetChoice(srtornot);
    switch (input) {
        case 1:
            cout << "Add people/UI.Insert" << endl;
            break;
        case 2:
            size = Per.size();
            for(int i = 0;i < size; i++)
            {
                Per[i].testwriter();
            }
            break;
        case 3:
            cout << "Search By name/UI.SearchByName" << endl;
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
