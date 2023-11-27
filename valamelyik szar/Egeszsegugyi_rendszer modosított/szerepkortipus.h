#ifndef SZEREPKORTIPUS_H
#define SZEREPKORTIPUS_H

#include "felhasznalo.h"
#include "szerepkor.h"

class Szerepkortipus
{
private:
    string Orvos,Beteg,Gyogyszertar;
public:
    Szerepkortipus();
    string SzerepkorMegallapit();
};

#endif // SZEREPKORTIPUS_H
