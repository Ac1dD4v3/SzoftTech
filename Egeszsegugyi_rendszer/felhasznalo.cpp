#include "felhasznalo.h"

Felhasznalo::Felhasznalo(const string &felh_nev_,
                         const string &felh_jelsz_,
                         const string &felh_email_):
    felh_nev(felh_nev_),
    felh_jelsz(felh_jelsz_),
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

void Felhasznalo::setFelhNev(string ujnev)
{
    felh_nev=ujnev;
}

string Felhasznalo::getFelhJelszo() const
{
    return felh_jelsz;
}

void Felhasznalo::setFelhJelszo(string ujjelszo)
{
    felh_jelsz=ujjelszo;
}

string Felhasznalo::getFelhEmail() const
{
    return felh_email;
}

void Felhasznalo::setFelhEmail(string ujmail)
{
    felh_email=ujmail;
}
