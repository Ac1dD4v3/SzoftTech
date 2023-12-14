#ifndef ORVOS_H
#define ORVOS_H
#include "felhasznalo.h"
#include "beteg.h"
#include <list>
#include <vector>
#include <algorithm>
#include <memory>
#include "recept.h"
#include <map>
#include "datum.h"
#include <iostream>
using namespace std;
namespace valami {
    class Orvos : public Felhasznalo
    {
    private:

        string OTH_kod;
        vector<BetegPtr> Betegek;
        vector<ReceptPtr> feladott_receptek;
        bool betegekBeolvasva = false;
        bool receptekBeolvasva = false;
    public:
        Orvos(int SzID, const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
        string getOTH_kod() const;
        void setOTH_kod(const string& ujoth);
        const vector<BetegPtr>& betegFelvetele();
        void betegTorlese();
        void receptLetrehozasa();
        void receptTorlese();
        virtual ~Orvos() {}
        const vector<BetegPtr>& getBetegek();
        void kiirBetegek();
        const vector<ReceptPtr>& getFeladottReceptek();
        void kiirReceptek();
        void betegLetrehozas();
    };

    typedef std::shared_ptr<Orvos> OrvosPtr;
}

#endif // ORVOS_H
