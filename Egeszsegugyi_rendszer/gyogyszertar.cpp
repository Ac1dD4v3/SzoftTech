#include "gyogyszertar.h"

Gyogyszertar::Gyogyszertar(const string &nev_,
                           const string &tel_,
                           const string &email_,
                           const string &OTH_kod_):
    Felhasznalo(nev_,tel_,email_),
    OTH_kod(OTH_kod_)
{}
