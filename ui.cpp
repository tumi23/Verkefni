#include "ui.h"
#include <algorithm>

char UI::getInput() {
    char input = 0;
    cout << "Input: ";
    cin >> input;
    return input;
}

void UI::startLoop(vector<computer>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com) {
    d.dbStarter();

    while(chooser(Per,Comp,d,pom,com));
}

//Gives information on what the user wants to do
void UI::printMenu(int menu) {
    switch (menu) {
        case 0: cout << "(1)Add Person - (2)Display Persons - (3)Search by Person name - (4)Sort by Person\n(5)Add Computer - (6)Display computer - (7)Search by Computer name - (8)sort by Computer\n(9)Connect Person and Computer" << endl; break;
        case 1: cout << "Sort by:\n(1)First name\n(2)Last name\n(3)Sex\n(4)Date of birth\n(5)Date of death" << endl; break;
        case 2: cout << "Sort by:\n(1)Name\n(2)Year made\n(3)Type\n(4)If it was made or not\n" << endl; break;
        default: cout << "Error menu not found!" << endl;
    }
}       

bool UI::chooser(vector<Person>& Per, vector<computer>& Comp, Data& d, PersonWorkLayer& pom, computerWorkLayer& com) {
    string pId, cId, name;
    vector<string> comname;

    d.personLoad(Per);
    d.computerLoad(Comp);

    printMenu(0);
    switch (getInput()) {
        case '1': pom.insert(d,Per,Comp); break;
        case '2':
            for(size_t i = 0; i < Per.size(); i++)
            {
                cout << Per[i];
                pId = Per[i].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
            }
            break;
        case '3': pom.searchByName(Per); break;
        case '4':
            printMenu(1);
            switch(getInput()) {
                case '1': pom.sortName(Per); break;
                case '2': pom.sortLastName(Per); break;
                case '3': pom.sortSex(Per); break;
                case '4': pom.sortBirth(Per); break;
                case '5': pom.sortDeath(Per); break;
                default: cout << "Error wrong input!" << endl;
            }
            break;
        case '5': com.insert(Comp, d); break;
        case '6':
            for(size_t i = 0; i < Comp.size(); i++)
            {
                cout << Comp[i];
                cId = Comp[i].getcid();
                name = d.creatorLoad(cId);
                cout << "Creator: " << name << endl;
            }
            break;
        case '7': com.searchByName(Comp,d); break;
        case '8':
        printMenu(2);
            switch(getInput()){
            case '1': com.sortName(Comp,d); break;
            case '2': com.sortYearMade(Comp,d); break;
            case '3': com.sortType(Comp,d); break;
            case '4': com.sortMade(Comp,d); break;
            default: cout << "Error wrong input!" << endl;
            }
        case '9': pom.modifyConnection(d,Per,Comp); break;
        default: return false;
    }
    return true;
}
