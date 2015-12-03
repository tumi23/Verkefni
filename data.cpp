#include "data.h"

void Data::personLoad(vector<Person>& p)
{
    p.clear();
    ifstream file("personlist.csv");
    string firstname, lastname, sex, birthday, death;
    while(file.good())
    {
        getline(file, firstname, ',');
        getline(file, lastname, ',');
        getline(file, sex, ',');
        getline(file, birthday, ',');
        getline(file, death, ',');
        p.push_back(Person(firstname, lastname, sex, birthday, death));
    }
    file.close();
}

void Data::personSave(vector<Person>& p)
{
    ofstream newFile;
    newFile.open("personlist.csv");
    int size = p.size(),checker;
    checker = 0;
    for(int i = 0; i < size; i++)
    {
        if(checker == 0)
        {
        newFile << p[i].getfname() << "," << p[i].getlname() << "," << p[i].getsex() << "," << p[i].getbirth() << ","
        << p[i].getdeath();
        checker++;
        }
        else
        {
            newFile << "," << p[i].getfname() << "," << p[i].getlname() << "," << p[i].getsex() << "," << p[i].getbirth() << ","
            << p[i].getdeath();
        }
    }
    newFile.close();
}

void computerLoad(vector<Computers>& Comp)
{
    Comp.clear();
    ifstream file("computerlist.csv");
    string name, yearMade, type, made;
    while(file.good())
    {
        getline(file, name, ',');
        getline(file, yearMade, ',');
        getline(file, type, ',');
        getline(file, made, ',');
        Comp.push_back(Computers(name, yearMade, type, made));
    }
    file.close();
}

void computerSave(vector<Computers>& Comp)
{
    ofstream newFile;
    newFile.open("computerlist.csv");
    int size = Comp.size(),checker;
    checker = 0;
    for(int i = 0; i < size; i++)
    {
        if(checker == 0)
        {
        newFile << Comp[i].getname() << "," << Comp[i].getyearMade() << "," << Comp[i].gettype() << "," << Comp[i].getmade();
        checker++;
        }
        else
        {
            newFile << "," << Comp[i].getname() << "," << Comp[i].getyearMade() << "," << Comp[i].gettype() << "," << Comp[i].getmade();
        }
    }
    newFile.close();
}
