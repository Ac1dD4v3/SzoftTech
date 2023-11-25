#ifndef GYOGYSZERTAR_H
#define GYOGYSZERTAR_H

#include <list>
#include "felhasznalo.h"
#include "gyogyszer.h"

class Gyogyszertar : public Felhasznalo
{
private:
    string OTH_kod;
    list<Gyogyszer> Elerhetok;
public:
    Gyogyszertar(const string &nev_, const string &tel_, const string &email_, const string& OTH_kod_);
    void receptTorlese();
    void elerhetoGyogyszerekListazasa()const;
    void elerhetoGyogyszerekTorlese();
    void elerhetoGyogyszerekHozzaadasa();
};

#endif // GYOGYSZERTAR_H
