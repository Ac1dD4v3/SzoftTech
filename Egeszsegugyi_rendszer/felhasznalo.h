#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
# include <string>
using namespace std;
class Felhasznalo
{
    int SzID;
    string felh_nev, felh_tel, felh_email;

public:
    Felhasznalo(const string& felh_nev_, const string& felh_tel_, const string& felh_email_);
    int getSzID()const;
    string getFelhNev()const;
    string getFelhTel()const;
    string getFelhEmail()const;
    void receptMegtekintes()const;
};

#endif // FELHASZNALO_H
