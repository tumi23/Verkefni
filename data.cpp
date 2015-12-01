#include "data.h"
#include "person.h"
#include "ui.h"

using namespace std;

Data::Data()
{

}

void Data::load(vector<Person>& p)
{
    string text;
    vector<string> info;
    ifstream file("c:/Users/Tumi/Desktop/test.csv");
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

//
//void Data::save(vector<Person> p)
//{
//    ofstream newFile;
//    string filename;
//    newFile.open(filename);
//    p.size() = size;
//    for(int i = 0; i < size; i++)
//    {
//        newFile << p[i].firstname << " , " << p[i].lastname << ", " << p[i].sex << " , " << p[i].birthday << " , "
//        << p[i].death;
//    }
//    newFile.close();
