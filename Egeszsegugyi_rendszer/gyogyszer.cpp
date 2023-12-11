#include "gyogyszer.h"
using namespace valami;
string Gyogyszer::getNev() const
{
    return Nev;
}

void Gyogyszer::setNev(const string &newNev)
{
    Nev = newNev;
}

string Gyogyszer::getLejarati_datum() const
{
    return Lejarati_datum;
}

void Gyogyszer::setLejarati_datum(int newLejarati_datum)
{
    Lejarati_datum = newLejarati_datum;
}

string Gyogyszer::getFelhasznalasiUtmutato() const
{
    return FelhasznalasiUtmutato;
}

void Gyogyszer::setFelhasznalasiUtmutato(const string &newFelhasznalasiUtmutato)
{
    FelhasznalasiUtmutato = newFelhasznalasiUtmutato;
}

Gyogyszer::Gyogyszer(const string &Nev, string Lejarati_datum, const string &FelhasznalasiUtmutato):
    Nev(Nev),
    Lejarati_datum(Lejarati_datum),
    FelhasznalasiUtmutato(FelhasznalasiUtmutato)
{}
