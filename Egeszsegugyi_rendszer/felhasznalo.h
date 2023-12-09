#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;
enum FelhasznaloTipus {
    ORVOS = 1,
    BETEG = 2,
    GYOGYSZERTAR = 3
};

class Felhasznalo
{
    int SzID;
    string felh_nev, felh_jelsz, felh_email;
    FelhasznaloTipus tipus;

public:
    Felhasznalo(int SzID,const string& felh_nev_, const string& felh_jelsz_, const string& felh_email_, const FelhasznaloTipus tipus);
    int getSzID()const;
    string getFelhNev()const;
    void setFelhNev(const string& ujnev);
    string getFelhJelszo()const;
    void setFelhJelszo(const string& ujjelszo);
    string getFelhEmail()const;
    void setFelhEmail(const string& ujmail);
    FelhasznaloTipus getTipus() {
        return tipus;
    }

    virtual ~Felhasznalo() {}
};

#endif // FELHASZNALO_H
