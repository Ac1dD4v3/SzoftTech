#ifndef BETEG_H
#define BETEG_H

#include <map>
#include "felhasznalo.h"
#include "datum.h"
#include "recept.h"

using namespace std;
class Beteg : public Felhasznalo
{
private:
    string TAJ_szam;
//    map<Datum,Recept> receptek;
public:
    Beteg(const string &nev_,const string &jelsz_, const string &email_, const string& TAJ_szam_);
    string getTajSzam()const;
    void receptIgenylese();
    void segitseg();
};

#endif // BETEG_H
