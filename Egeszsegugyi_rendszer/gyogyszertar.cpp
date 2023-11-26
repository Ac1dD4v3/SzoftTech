#include "gyogyszertar.h"

string Gyogyszertar::getOTH_kod() const
{
    return OTH_kod;
}

void Gyogyszertar::setOTH_kod(const string &newOTH_kod)
{
    OTH_kod = newOTH_kod;
}

Gyogyszertar::Gyogyszertar(const string &nev_,
                           const string &jelsz_,
                           const string &email_,
                           const string &OTH_kod_):
    Felhasznalo(nev_,jelsz_,email_),
    OTH_kod(OTH_kod_)
{}
