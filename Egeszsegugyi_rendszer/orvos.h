#ifndef ORVOS_H
#define ORVOS_H

#include "felhasznalo.h"

class Orvos : public Felhasznalo
{
private:
    string OTH_kod;
public:
    Orvos(const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
    string getOTH_kod() const;
    void setOTH_kod(string ujoth);
    void betegFelvetele();
    void betegTorlese();
    void receptLetrehozasa();
    void receptTorlese();

};

#endif // ORVOS_H
