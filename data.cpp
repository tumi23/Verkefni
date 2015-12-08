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
    QString firstname = QString::fromStdString(fname);
    QString lastname = QString::fromStdString(lname);
    QString tsex = QString::fromStdString(sex);
    QString tbirth = QString::fromStdString(birth);
    QString tdeath = QString::fromStdString(death);
    query.prepare("INSERT INTO person (firstname,lastname,sex,YearOfBirth,YearOfDeath) "
                  "VALUES (:firstname, :lastname, :sex, :YearOfBirth, :YearOfDeath)");
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":sex", tsex);
    query.bindValue(":YearOfBirth", tbirth);
    query.bindValue(":YearOfDeath", tdeath);
    query.exec();
}

void Data::computerLoad(vector<computer>& Comp)//Fall sem sér um að lesa inn allt úr computer
{                                               //töflunni í gagnagrunninum og setja í vector
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM computer");//Sér um að gefa Query SQL skipun sem Query mun
    Comp.clear();                            //því nota til að draga gögn úr gagnagrunninum.
    string name, yearMade, type, made;
    query.exec();
    while(query.next())//Lúpan sem sér um að draga hverja röð úr gagnagrunninum til að setja í vector.
    {
        name = query.value("name").toString().toStdString();
        yearMade= query.value("yearMade").toString().toStdString();
        type = query.value("type").toString().toStdString();
        made = query.value("doesItExist").toString().toStdString();
        Comp.push_back(computer(name, yearMade, type, made));
    }
    db.close();
}

<<<<<<< HEAD
void Data::computerSave(string name, string yearMade, string type, string doesItExist)
=======
void Data::computerSave(vector<computer>& Comp)
>>>>>>> b34d0c64081eb60ce89000e3e5e54b91bac6033f
{
    db.open();
    QSqlQuery query(db);
    QString tname = QString::fromStdString(name);
    QString tyearMade = QString::fromStdString(yearMade);
    QString ttype = QString::fromStdString(type);
    QString tdoesItExist = QString::fromStdString(doesItExist);
    query.prepare("INSERT INTO computers (name,yearMade,type,doesItExist) "
                  "VALUES (:name,:yearMade,:type,:doesItExist)");
    query.bindValue(":name", tname);
    query.bindValue(":yearMade", tyearMade);
    query.bindValue(":type", ttype);
    query.bindValue(":doesItExist", tdoesItExist);
    query.exec();
}
