#include "data.h"
#include "person.h"
#include "ui.h"

using namespace std;

Data::Data()
{

}

void Data::load(vector<Person>& p)
{
    p.clear();
    ifstream file("listi.csv");
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

void Data::save(vector<Person>& p)
{
    ofstream newFile;
    newFile.open("listi.csv");
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
