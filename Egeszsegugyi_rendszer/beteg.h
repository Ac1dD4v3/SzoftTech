#ifndef BETEG_H
#define BETEG_H

#include <map>
#include "felhasznalo.h"
#include "datum.h"
#include "recept.h"
#include <vector>
#include <fstream>
#include <memory>
#include "hiba.h"
namespace valami{
class Beteg : public Felhasznalo
{
private:
    int TAJ_szam;
    vector<ReceptPtr> orvosaltal_receptek;
    vector<ReceptPtr> igenyeltreceptek;
public:
    Beteg(int SzID,const string &nev_,const string &jelsz_, const string &email_, int TAJ_szam_);
    int getTajSzam()const;
    void setTajSzam(int ujtaj);
    void receptIgenylese();
    void receptekMegtekintese();
    void segitseg();
    const vector<ReceptPtr>& getF_Receptek() const;
    void addF_Receptek(const ReceptPtr& recept);
};
typedef std::shared_ptr<Beteg> BetegPtr;
}
#endif // BETEG_H
