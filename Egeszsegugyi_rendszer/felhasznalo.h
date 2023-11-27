#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
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
};

#endif // FELHASZNALO_H
