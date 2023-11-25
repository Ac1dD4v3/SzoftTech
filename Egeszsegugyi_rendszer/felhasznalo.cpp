#include "felhasznalo.h"

Felhasznalo::Felhasznalo(const string &felh_nev_,
                         const string &felh_tel_,
                         const string &felh_email_):
    felh_nev(felh_nev_),
    felh_tel(felh_tel_),
    felh_email(felh_email_)
{}

int Felhasznalo::getSzID() const
{
    return this->SzID;
}

string Felhasznalo::getFelhNev() const
{
    return this->felh_nev;
}

string Felhasznalo::getFelhTel() const
{
    return this->getFelhTel();
}

string Felhasznalo::getFelhEmail() const
{
    return this->getFelhEmail();
}
