#include "datum.h"
using namespace valami;
void Datum::setDatum(const string &newDatum)
{
    datum = newDatum;
}

Datum::Datum(const string &datum):
    datum(datum)
{}
