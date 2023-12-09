#include "felhasznalo.h"

Felhasznalo::Felhasznalo(int SzID, const string &felh_nev_,
                         const string &felh_jelsz_,
                         const string &felh_email_,
                         const FelhasznaloTipus tipus):
    SzID(SzID),
    felh_nev(felh_nev_),
    felh_jelsz(felh_jelsz_),
    felh_email(felh_email_),
    tipus(tipus)
{}

int Felhasznalo::getSzID() const
{
    return SzID;
}

string Felhasznalo::getFelhNev() const
{
    return felh_nev;
}

void Felhasznalo::setFelhNev(const string &ujnev)
{
    felh_nev=ujnev;
}

string Felhasznalo::getFelhJelszo() const
{
    return felh_jelsz;
}

void Felhasznalo::setFelhJelszo(const string &ujjelszo)
{
    felh_jelsz=ujjelszo;
}

string Felhasznalo::getFelhEmail() const
{
    return felh_email;
}

void Felhasznalo::setFelhEmail(const string& ujmail)
{
    felh_email=ujmail;
}
