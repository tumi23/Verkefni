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
    string p_id, firstName, lastName, sex, birthDay, death;
    query.exec();
    while(query.next())//Lúpan sem sér um að draga hverja röð úr gagnagrunninum til að setja í vector.
    {
        p_id = query.value("p_id").toString().toStdString();
        firstName = query.value("firstname").toString().toStdString();
        lastName = query.value("lastname").toString().toStdString();
        sex = query.value("sex").toString().toStdString();
        birthDay = query.value("YearOfBirth").toString().toStdString();
        death = query.value("YearOfDeath").toString().toStdString();
        p.push_back(Person(p_id, firstName, lastName, sex, birthDay, death));
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
    query.prepare("INSERT INTO Person (firstname,lastname,sex,YearOfBirth,YearOfDeath) "
                  "VALUES (:firstname, :lastname, :sex, :YearOfBirth, :YearOfDeath)");
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":sex", tsex);
    query.bindValue(":YearOfBirth", tbirth);
    query.bindValue(":YearOfDeath", tdeath);
    query.exec();
}

void Data::computerLoad(vector<computer>& Comp)
{
    db.open();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM computers");//Sér um að gefa Query SQL skipun sem Query mun
    Comp.clear();                            //því nota til að draga gögn úr gagnagrunninum.
    string c_id, name, yearMade, type, made;
    query.exec();
    while(query.next())//Lúpan sem sér um að draga hverja röð úr gagnagrunninum til að setja í vector.
    {
        c_id = query.value("c_id").toString().toStdString();
        name = query.value("name").toString().toStdString();
        yearMade= query.value("yearMade").toString().toStdString();
        type = query.value("type").toString().toStdString();
        made = query.value("doesItExist").toString().toStdString();
        Comp.push_back(computer(c_id ,name, yearMade, type, made));
    }
    db.close();
}

void Data::computerSave(string name, string yearMade, string type, string doesItExist)
{
    db.open();
    QSqlQuery query(db);
    QString tname = QString::fromStdString(name);
    QString tyearMade = QString::fromStdString(yearMade);
    QString ttype = QString::fromStdString(type);
    QString tdoesItExist = QString::fromStdString(doesItExist);
    query.prepare("INSERT INTO Computers (name,yearMade,type,doesItExist) "
                  "VALUES (:name,:yearMade,:type,:doesItExist)");
    query.bindValue(":name", tname);
    query.bindValue(":yearMade", tyearMade);
    query.bindValue(":type", ttype);
    query.bindValue(":doesItExist", tdoesItExist);
    query.exec();
}

string Data::creatorLoad(string c_id)
{
    db.open();
    QSqlQuery query(db);
    QString id = QString::fromStdString(c_id);
    query.prepare("SELECT Person.firstname,Person.lastname FROM Person "
                  "JOIN IdConnector ON person.p_id = IdConnector.p_id "
                  "JOIN Computers ON IdConnector.c_id = Computers.c_id WHERE Computers.c_id = :number "
                  "ORDER BY Person.firstname");
    query.bindValue(":number", id);
    string firstname, lastname, fullname;
    query.exec();
    while(query.next())
    {
        firstname = query.value("firstname").toString().toStdString();
        lastname = query.value("lastname").toString().toStdString();
        fullname = firstname + " " + lastname;
    }
    db.close();
    return fullname;
}

vector<string> Data::creatorLoad2(string p_id)
{
    db.open();
    QSqlQuery query(db);
    QString id = QString::fromStdString(p_id);
    query.prepare("SELECT Computers.name FROM Computers "
                  "JOIN IdConnector ON Computers.c_id = IdConnector.c_id "
                  "JOIN Person ON IdConnector.p_id = Person.p_id WHERE Person.p_id = :number "
                  "ORDER BY Person.firstname");
    query.bindValue(":number", id);
    vector<string> name;
    string tname;
    query.exec();
    while(query.next())
    {
        name.push_back(query.value("name").toString().toStdString());
    }
    db.close();
    return name;
}

void Data::idConnectSave(string c_id, string p_id)
{
    db.open();
    QSqlQuery query(db);
    QString tcid = QString::fromStdString(c_id);
    QString tpid = QString::fromStdString(p_id);
    query.prepare("INSERT INTO IdConnector(c_id,p_id) "
                  "VALUES (:cid,:pid)");
    query.bindValue(":cid", tcid);
    query.bindValue(":pid", tpid);
    query.exec();
}
