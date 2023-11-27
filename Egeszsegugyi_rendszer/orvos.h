#ifndef ORVOS_H
#define ORVOS_H
#include "felhasznalo.h"
#include "beteg.h"
#include <list>
#include <vector>
class Orvos : public Felhasznalo
{
private:
    string OTH_kod;
    vector<string> Betegek;
public:

    Orvos(const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
    string getOTH_kod() const;
    void setOTH_kod(const string& ujoth);
    void betegFelvetele();
    vector<string> betegTorlese();
    void receptLetrehozasa();
    void receptTorlese();
};

#endif // ORVOS_H
