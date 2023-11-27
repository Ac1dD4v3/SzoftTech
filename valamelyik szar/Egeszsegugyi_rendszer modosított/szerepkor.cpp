#include "szerepkor.h"


Szerepkor::Szerepkor(const string &Szerep_):
    Szerep(Szerep_)
{}

string Szerepkor::getSzerep() const
{
    return SzerepkorMegallapit();
}

int Szerepkor::getSzID() const //szerepazonosíto nem SZID mivel az egy egyedi számsor lesz
{
    if (getSzerep() == "Orvos")
    {
        return 1;
    }
    else if(getSzerep() == "Beteg")
    {
        return 2;
    }
    else if(getSzerep() == "Gyogyszertar")
    {
        return 3;
    }
    else
        return 0; // hiba osztály egyik exception (ha nem jó a szerep)
}
