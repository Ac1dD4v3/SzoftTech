#ifndef BETEG_H
#define BETEG_H

#include <map>
#include "felhasznalo.h"
#include "datum.h"
#include "recept.h"
#include <vector>

class Beteg : public Felhasznalo
{
private:
    int TAJ_szam;
    vector<string> receptek;
public:
    Beteg(const string &nev_,const string &jelsz_, const string &email_, int TAJ_szam_);
    int getTajSzam()const;
    void setTajSzam(int ujtaj);
    void receptIgenylese();
    void segitseg();
};

#endif // BETEG_H
