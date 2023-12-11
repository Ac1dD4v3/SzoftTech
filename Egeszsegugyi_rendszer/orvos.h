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
        vector<Beteg> Betegek;
        vector<Recept> feladott_receptek;
    public:
        Orvos(int SzID, const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
        string getOTH_kod() const;
        void setOTH_kod(const string& ujoth);
        vector<Beteg> betegFelvetele();
        void betegTorlese();
        void receptLetrehozasa();
        void receptTorlese();
        virtual ~Orvos() {}
        void getBetegek() const;
        void getFeladott_receptek() const;
    };

    typedef std::shared_ptr<Orvos> OrvosPtr;
}

#endif // ORVOS_H
