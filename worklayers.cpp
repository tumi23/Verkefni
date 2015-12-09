#include "worklayers.h"

/*Akvodum ad bua til worklayer sem virkar sem millilidur a data og UI, thannig ad notandi bidur
um ad gera eitthvad og thad kallar a eitt af functionunum fyrir nedan thad er ad segja
computerWorkLayer fyrir allt sem tengist Computers toflunni og PersonWorkLayer fyrir
allt sem tengist person toflunni, og worklayer inniheldur tvo klasa sem var thaegilegra
en ad hafa tvaer mismunandi skrar fyrir compworklayer og persworklayer, eini minusinn er ad
skrainn er stor og mikil og thvi sma ljot ad sja en hun er samt eins vel sett upp
og vid gatum imyndad okkur
*/
void computerWorkLayer::insert(vector<computer>& Comp, Data& d)
{
    string name, yearMade, type, doesItExist;
    bool breaker;
    breaker = false;
    cout << "Name: " << endl;
    cin >> name;
    cout << "Year made: " << endl;
    cin >> yearMade;
    cout << "Type: " << endl;
    cin >> type;
    cout << "Was it made? (Answer with Y for Yes or N for No): " << endl;
    cin >> doesItExist;
    d.computerSave(name,yearMade,type,doesItExist);
}

void computerWorkLayer::searchByName(vector<computer>& Comp, Data& d)
{
    string cId;
    vector<string> crtname;
    string name;
    cout << "Type in a name to search for: " << endl;
    cin >> name;
    int size = Comp.size();
    for(int i = 0; i < size; i++)
    {
        if(Comp[i].getname().find(name) != string::npos)
        {
            cout << Comp[i];
            cId = Comp[i].getcid();//Her saekir forritid id a tolvunni sem verid er ad skrifa ut og notar til ad finna Skapandan
            crtname.clear();       //og er thetta endurnotad i hverju falli sem tengist thvi ad skrifa a toflu ut.
            crtname = d.creatorLoad(cId);
            cout << "Creators: ";
            for(unsigned int i = 0; i < crtname.size();i++)
            {
                cout << crtname[i] << ", ";
            }
            cout << endl;
        }
    }
}

void computerWorkLayer::sortName(vector<computer>& Comp, Data& d)
{
    string cId;
    vector<string> crtname;
    vector<string> name;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        name.push_back(Comp[i].getname());
    }
    sort(name.begin(), name.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getname() == name[i])
            {
                cout << Comp[o];
                cId = Comp[o].getcid();
                crtname.clear();
                crtname = d.creatorLoad(cId);
                cout << "Creators: ";
                for(unsigned int i = 0; i < crtname.size();i++)
                {
                    cout << crtname[i] << ", ";
                }
                cout << endl;
            }
        }
    }
}

void computerWorkLayer::sortYearMade(vector<computer>& Comp, Data& d)
{
    string cId;
    vector<string> crtname;
    vector<string> yearMade;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        yearMade.push_back(Comp[i].getyearMade());
    }
    sort(yearMade.begin(), yearMade.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getyearMade() == yearMade[i])
            {
                cout << Comp[o];
                cId = Comp[o].getcid();
                crtname.clear();
                crtname = d.creatorLoad(cId);
                cout << "Creators: ";
                for(unsigned int i = 0; i < crtname.size();i++)
                {
                    cout << crtname[i] << ", ";
                }
                cout << endl;
            }
        }
    }
}

void computerWorkLayer::sortType(vector<computer>& Comp, Data& d)
{
    string cId;
    vector<string> crtname;
    vector<string> type;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        type.push_back(Comp[i].gettype());
    }
    sort(type.begin(), type.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].gettype() == type[i] && count != Comp.size())
            {
                cout << Comp[o];
                cId = Comp[o].getcid();
                crtname.clear();
                crtname = d.creatorLoad(cId);
                cout << "Creators: ";
                for(unsigned int i = 0; i < crtname.size();i++)
                {
                    cout << crtname[i] << ", ";
                }
                cout << endl;
                count++;
            }
        }
    }
}

void computerWorkLayer::sortMade(vector<computer>& Comp, Data& d)
{
    string cId;
    vector<string> crtname;
    vector<string> made;
    int count = 0;
    for(int i = 0; i < Comp.size(); i++)
    {
        made.push_back(Comp[i].getmade());
    }
    sort(made.begin(), made.end());
    for(size_t i = 0; i < Comp.size(); i++)
    {
        for(size_t o = 0; o < Comp.size(); o++)
        {
            if(Comp[o].getmade() == made[i] && count != Comp.size())
            {
                cout << Comp[o];
                cId = Comp[o].getcid();
                crtname.clear();
                crtname = d.creatorLoad(cId);
                cout << "Creators: ";
                for(unsigned int i = 0; i < crtname.size();i++)
                {
                    cout << crtname[i] << ", ";
                }
                cout << endl;
                count++;
            }
        }
    }
}

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

void PersonWorkLayer::insert(Data& d, vector<Person>& Per, vector<computer>& Comp)
{
    string fname, lname, sex, birth, death,yesOrNo,cId,pId;
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
        cout << "Is the person still alive?\nY/N:";
        cin >> yesOrNo;
        if(yesOrNo == "N" || yesOrNo == "n")
        {
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
        else
        {
            death = "Alive";
            breaker = true;
        }
   }
    d.personSave(fname,lname,sex,birth,death);
}

void PersonWorkLayer::searchByName(vector<Person>& Per,Data& d)
{
    string name,pId;
    vector<string> comname;
    cout << "Type in a name to search for: " << endl;
    cin >> name;
    int size = Per.size();
    for(int i = 0; i < size; i++)
    {
        if(Per[i].getfname().find(name) != string::npos || Per[i].getlname().find(name) != string::npos)
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
    }
}

void PersonWorkLayer::sortName(vector<Person>& Per,Data& d)
{
    string pId;
    vector<string> comname;
    vector<string> firstname;
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
            {
                cout << Per[o];
                pId = Per[o].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
            }
        }
    }
}

void PersonWorkLayer::sortLastName(vector<Person>& Per,Data& d)
{
    string pId;
    vector<string> comname;
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
            {
                cout << Per[o];
                pId = Per[o].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
            }
        }
    }
}

void PersonWorkLayer::sortSex(vector<Person>& Per,Data& d)
{
    string pId;
    vector<string> comname;
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
                pId = Per[o].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
                count++;
            }
        }
    }
}

void PersonWorkLayer::sortBirth(vector<Person>& Per,Data& d)
{
    string pId;
    vector<string> comname;
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
                pId = Per[o].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
                    count++;
            }
        }
    }
}

void PersonWorkLayer::sortDeath(vector<Person>& Per,Data& d)
{
    string pId;
    vector<string> comname;
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
                pId = Per[o].getpid();
                comname.clear();
                comname = d.creatorLoad2(pId);
                cout << "Computers Created: ";
                for(unsigned int i = 0; i < comname.size();i++)
                {
                    cout << comname[i] << ", ";
                }
                cout << endl;
                    count++;
            }
        }
    }
}

void PersonWorkLayer::modifyConnection(Data& d, vector<Person>& Per, vector<computer>& Comp)
{
   string tcom,tfper,tlper,cId,pId;
   d.personLoad(Per);

   cout << "\nHere's a list of all Computers in database, type the name of the one you want to connect:";
   for(int i = 0; i < Comp.size();i++)
   {
       cout << Comp[i].getname() << ", " ;
   }
   cout << "\nPlease input the name of the computer: " << endl;
   cin >> tcom;

   cout << "Here's a list of all Person in database, type the name of the one you want to connect:\n";
   for(int i = 0; i < Per.size();i++)
   {
       cout << Per[i].getfname() << " " << Per[i].getlname() << ", ";
   }
   cout << "\nPlease input the name of the person to connect: " << endl;
   cout << "First Name: ";
   cin >> tfper;
   cout << "Last Name: ";
   cin >> tlper;

   for(int i = 0; i < Comp.size();i++)
   {
       if(Comp[i].getname() == tcom)
       {
           cId = Comp[i].getcid();
       }
   }
   for(int j = 0;j < Per.size(); j++)
   {
       string fullname = Per[j].getfname() + " " + Per[j].getlname();
       string fullname2 = tfper + " " + tlper;
       if(fullname == fullname2)
       {
           pId = Per[j].getpid();
       }
   }
   d.idConnectSave(cId,pId);
   cout << tcom << " and " << tfper << " " << tlper << " are now connected." << endl;
}
