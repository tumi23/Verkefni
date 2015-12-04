#include "personworklayer.h"
bool PersonWorkLayer::NameChecker(string fname, string lname, vector<Person>& Per)
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

void PersonWorkLayer::insert(Data& d, vector<Person>& Per)
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
    d.personSave(Per);
}

void PersonWorkLayer::searchByName(vector<Person>& Per)
{
    string name;
    cout << "Type in a name to search for: " << endl;
    cin >> name;
    int size = Per.size();
    for(int i = 0; i < size; i++)
    {
        if(Per[i].getfname().find(name) != string::npos || Per[i].getlname().find(name) != string::npos)
        {
            cout << Per[i];
        }
    }
}

void PersonWorkLayer::sortName(vector<Person>& Per)
{
    vector<string> firstname;
    int count = 0;
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
            cout << Per[o];
        }
    }
}

void PersonWorkLayer::sortLastName(vector<Person>& Per)
{
    vector<string> lastname;
    int count = 0;
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
            cout << Per[o];
        }
    }
}

void PersonWorkLayer::sortSex(vector<Person>& Per)
{
    vector<string> sexes;
    int count = 0;
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
                cout << Per[o];
                count++;
            }
        }
    }
}

void PersonWorkLayer::sortBirth(vector<Person>& Per)
{
    vector<string> births;
    int count = 0;
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
                cout << Per[o];
                count++;
            }
        }
    }
}

void PersonWorkLayer::sortDeath(vector<Person>& Per)
{
    vector<string> deaths;
    int count = 0;
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
                cout << Per[o];
                count++;
            }
        }
    }
}
