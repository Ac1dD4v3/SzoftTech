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
    Felhasznalo();
    int getSzID()const;
    void receptMegtekintes()const;
};

#endif // FELHASZNALO_H
