#ifndef GYOGYSZER_H
#define GYOGYSZER_H

#include <string>
#include "datum.h"
using namespace std;
class Gyogyszer
{
private:
    string gyogyszer_nev, felhasznalasi_utmutato;
    Datum lejarati_datum;
public:
    Gyogyszer();
};

#endif // GYOGYSZER_H
