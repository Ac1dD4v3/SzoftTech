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
    map<const Datum ,const Recept> receptek;
public:
    Beteg();
    void receptIgenylese();
    void segitseg();
};

#endif // BETEG_H
