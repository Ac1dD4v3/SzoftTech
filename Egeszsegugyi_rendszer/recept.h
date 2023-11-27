#ifndef RECEPT_H
#define RECEPT_H

#include "datum.h"
#include "beteg.h"
#include "orvos.h"
#include "gyogyszer.h"
#include "felhasznalo.h"

class Recept
{
private:
    Datum lejarati_datum;
    string beteg_neve,felado_orvos,gyogyszer_neve;
public:
    Recept(const Datum& datum_, const string& beteg_neve, const string& felado_orvos_, const string& gyogyszer_neve_);
    Datum getLejaratiDatum()const;
    string getBetegNeve()const;
    string getFeladoOrvos()const;
    string getGyogyszerNeve()const;
};

#endif // RECEPT_H
