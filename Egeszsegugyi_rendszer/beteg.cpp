#include "beteg.h"

Beteg::Beteg(const string& nev_,
             const string &jelsz_,
             const string& email_,
             const string &TAJ_szam_):
    Felhasznalo(nev_,jelsz_,email_),
    TAJ_szam(TAJ_szam_)
{}

string Beteg::getTajSzam() const
{
    return TAJ_szam;
}
