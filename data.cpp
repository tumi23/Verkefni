#include "data.h"

void Data::dbStarter()//Fall sem sér um að skilgreina gagnagrunns breytuna.
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);
}

void Data::personLoad(vector<Person>& p) //Fall sem sér um að lesa inn allt úr Person
{                                        //töflunni í gagnagrunninum og setja í vector
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Person");//Sér um að gefa Query SQL skipun sem Query mun
    p.clear();                            //því nota til að draga gögn úr gagnagrunninum.
    string firstName, lastName, sex, birthDay, death;
    query.exec();
    while(query.next())//Lúpan sem sér um að draga hverja röð úr gagnagrunninum til að setja í vector.
    {
        firstName = query.value("firstname").toString().toStdString();
        lastName = query.value("lastname").toString().toStdString();
        sex = query.value("sex").toString().toStdString();
        birthDay = query.value("YearOfBirth").toString().toStdString();
        death = query.value("YearOfDeath").toString().toStdString();
        p.push_back(Person(firstName, lastName, sex, birthDay, death));
    }
    db.close();
}

void Data::personSave(string fname,string lname, string sex, string birth, string death)
{
    db.open();
    QSqlQuery query(db);
    string queryInsert = "INSERT INTO Person(firstname,lastname,sex,YearOfBirth,YearOfDeath) VALUES(" + fname + "," + lname + "," + sex + "," + birth + "," + death + ")";
    query.exec(QString(queryInsert.c_str()));
}

void Data::computerLoad(vector<Computers>& Comp)//Fall sem sér um að lesa inn allt úr Computers
{                                               //töflunni í gagnagrunninum og setja í vector
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Computers");//Sér um að gefa Query SQL skipun sem Query mun
    Comp.clear();                            //því nota til að draga gögn úr gagnagrunninum.
    string name, yearMade, type, made;
    query.exec();
    while(query.next())//Lúpan sem sér um að draga hverja röð úr gagnagrunninum til að setja í vector.
    {
        name = query.value("name").toString().toStdString();
        yearMade= query.value("yearMade").toString().toStdString();
        type = query.value("type").toString().toStdString();
        made = query.value("doesItExist").toString().toStdString();
        Comp.push_back(Computers(name, yearMade, type, made));
    }
    db.close();
}

void Data::computerSave(vector<Computers>& Comp)
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
