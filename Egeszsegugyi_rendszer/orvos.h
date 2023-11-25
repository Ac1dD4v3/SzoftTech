#ifndef ORVOS_H
#define ORVOS_H

#include "felhasznalo.h"

class Orvos : public Felhasznalo
{
private:
    string OTH_kod;
public:
    Orvos(const string &nev_, const string &tel_, const string &email_, const string& OTH_kod_);
    void betegFelvetele();
    void betegTorlese();
    void receptLetrehozasa();
    void receptTorlese();
};

#endif // ORVOS_H
