#include "ui.h"
#include <algorithm>

char UI::getInput() {
    char input = 0;
    cin >> input;
    return input;
}

void UI::UIDbChoseLooper(vector<computer>& Comp, vector<Person>& Per, Data& d, PersonWorkLayer& pom, computerWorkLayer& com) {
    d.dbStarter();
    d.personLoad(Per);
    d.computerLoad(Comp);

    while(true) {
        cout << "(1)Person Database - (2)Computer Database\n!Anything Else Quits!" << endl;
        switch (getInput()) {
            case '1': while(personChooser(Per,Comp,d,pom)); break;
            case '2': while(computerChooser(Comp,d,com)); break;
            default: return;
        }
    }
}

//Gives information on what the user wants to do
void UI::printMenu(string menu) {
    switch (menu) {
        case "personMain": cout << "\n(1)Add Person - (2)Display Persons - (3)Search by name\n(4)Sort - (5)Connect Computer and Person\n!Anything else returns you back to choose a database!\n" << endl; break;
        case "personSort": cout << "Sort by:\n(1)First name\n(2)Last name\n(3)Sex\n(4)Date of birth\n(5)Date of death" << endl; break;
        case "computerMain": cout << "\n(1)Add Computer\n(2)Display computer\n(3)Search by name\n(4)sort\n!Anything else returns you back to choose a database!\n" << endl; break;
        case "computerSort": cout << "Sort by:\n(1)Name\n(2)Year made\n(3)Type\n(4)If it was made or not\n" << endl; break;
        default: cout << "Error menu not found!" << endl;
    }
}       

bool UI::personChooser(vector<Person>& Per,vector<computer>& Comp, Data& d,PersonWorkLayer& pom) {
    string pId, comname;\d.
    personLoad(Per);
    printMenu("personMain");
    switch (getInput()) {
        case '1': pom.insert(d,Per,Comp); break;
        case '2':
            for(size_t i = 0; i < Per.size(); i++)
            {
                cout << Per[i];
                pId = Per[i].getpid();
                comname = d.creatorLoad2(pId);
                cout << "Computer Created: " << comname << endl;
            }
            break;
        case '3': pom.searchByName(Per); break;
        case '4':
            printMenu("personSort");
            switch(getInput()) {
                case '1': pom.sortName(Per); break;
                case '2': pom.sortLastName(Per); break;
                case '3': pom.sortSex(Per); break;
                case '4': pom.sortBirth(Per); break;
                case '5': pom.sortDeath(Per); break;
                default: cout << "Error wrong input!" << endl;
            }
            break;
        case '5': pom.modifyConnection(d,Per,Comp); break;
        default: return false;
    }
    return true;
}

bool UI::computerChooser(vector<computer>& Comp, Data& d,computerWorkLayer& com) {
    d.computerLoad(Comp);
    string cId, name;
    printMenu("computerMain");
    switch (getInput()) {
        case '1': com.insert(Comp, d); break;
        case '2':
            for(size_t i = 0; i < Comp.size(); i++)
            {
                cout << Comp[i];
                cId = Comp[i].getcid();
                name = d.creatorLoad(cId);
                cout << "Creator: " << name << endl;
            }
            break;
        case '3': com.searchByName(Comp,d); break;
        case '4':
            printMenu("computerSort");
            switch(getInput()){
                case '1': com.sortName(Comp,d); break;
                case '2': com.sortYearMade(Comp,d); break;
                case '3': com.sortType(Comp,d); break;
                case '4': com.sortMade(Comp,d); break;
                default: cout << "Error wrong input!" << endl;
            }
            break;
        default: return false;
    }
    return true;
}
