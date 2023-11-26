#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
# include <string>
using namespace std;
class Felhasznalo
{
    int SzID;
    string felh_nev, felh_jelsz, felh_email;

public:
    Felhasznalo(const string& felh_nev_, const string& felh_jelsz_, const string& felh_email_);
    int getSzID()const;
    string getFelhNev()const;
    void setFelhNev(const string& ujnev);
    string getFelhJelszo()const;
    void setFelhJelszo(const string& ujjelszo);
    string getFelhEmail()const;
    void setFelhEmail(const string& ujmail);
    void receptMegtekintes()const;
//    friend ostream& operator<<(ostream& os,const Felhasznalo& felh){
//        os<<felh;
//        return os;
//    }
};

#endif // FELHASZNALO_H
