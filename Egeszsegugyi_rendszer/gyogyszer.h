#ifndef GYOGYSZER_H
#define GYOGYSZER_H

#include <string>

using namespace std;

class Gyogyszer
{
private:
    string Nev, FelhasznalasiUtmutato;
    int Lejarati_datum;
public:
    Gyogyszer(const string& Nev, int Lejarati_datum, const string& FelhasznalasiUtmutato,);
};

#endif // GYOGYSZER_H
