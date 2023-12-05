#ifndef BETEG_H
#define BETEG_H

#include <map>
#include "felhasznalo.h"
#include "datum.h"
#include "recept.h"
#include <vector>
namespace valami{
class Beteg : public Felhasznalo
{
private:
    int TAJ_szam;
    vector<Recept> receptek;
public:
    Beteg(int SzID,const string &nev_,const string &jelsz_, const string &email_, int TAJ_szam_);
    int getTajSzam()const;
    void setTajSzam(int ujtaj);
    void receptIgenylese();
    void segitseg();
    vector<Recept> getReceptek() const;
    void setReceptek(const vector<Recept> &newReceptek);
};
}
#endif // BETEG_H
