#include "orvos.h"

string Orvos::getOTH_kod() const
{
    return OTH_kod;
}

void Orvos::setOTH_kod(const string &ujoth)
{
    OTH_kod=ujoth;
}

Orvos::Orvos(const string &nev_,
             const string &jelsz_,
             const string &email_,
             const string &OTH_kod_):
    Felhasznalo(nev_,jelsz_,email_),
    OTH_kod(OTH_kod_)
{}
