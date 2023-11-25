#ifndef RECEPT_H
#define RECEPT_H

#include "datum.h"
#include "beteg.h"
#include "orvos.h"
#include "gyogyszer.h"

class Recept
{
private:
    Datum lejarati_datum;
    string beteg_neve,felado_orvos,gyogyszer_neve;
public:
    Recept();
};

#endif // RECEPT_H
