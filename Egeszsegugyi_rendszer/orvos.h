#ifndef ORVOS_H
#define ORVOS_H

#include "felhasznalo.h"

class Orvos : public Felhasznalo
{
private:
    string OTH_kod;
public:
    Orvos();
    void betegFelvetele();
    void betegTorlese();
    void receptLetrehozasa();
    void receptTorlese();
};

#endif // ORVOS_H
