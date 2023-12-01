#ifndef ORVOS_H
#define ORVOS_H
#include "felhasznalo.h"
#include "beteg.h"
#include <list>
#include <vector>
#include <algorithm>


class Orvos : public Felhasznalo
{
private:
    string OTH_kod;
    vector<Beteg> Betegek;
public:

    Orvos(int SzID,const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
    string getOTH_kod() const;
    void setOTH_kod(const string& ujoth);
    vector<Beteg> betegFelvetele();
    vector<Beteg> betegTorlese();
    void receptLetrehozasa();
    void receptTorlese();
};

#endif // ORVOS_H
