#ifndef BETEG_H
#define BETEG_H

#include <map>
#include "felhasznalo.h"
#include "datum.h"
#include "recept.h"
#include <vector>
#include <fstream>
#include <memory>
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
        void receptekMegtekintese();
        void segitseg();
        vector<Recept> getReceptek() const;
        void setReceptek(const vector<Recept> &newReceptek);
    };
    typedef std::shared_ptr<Beteg> BetegPtr;
}
#endif // BETEG_H
