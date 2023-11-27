#include "beteg.h"

Beteg::Beteg(const string& nev_,
             const string &jelsz_,
             const string& email_,
             int TAJ_szam_):
    Felhasznalo(nev_,jelsz_,email_),
    TAJ_szam(TAJ_szam_)
{}

int Beteg::getTajSzam() const
{
    return TAJ_szam;
}

void Beteg::setTajSzam(int ujtaj)
{
    TAJ_szam=ujtaj;
}
