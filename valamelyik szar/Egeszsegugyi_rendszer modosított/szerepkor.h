#ifndef SZEREPKOR_H
#define SZEREPKOR_H

#include "felhasznalo.h"
#include "szerepkortipus.h"

class Szerepkor
{
private:
    int SzID; //1 orvos, 2 beteg, 3 gyogy
    string Szerep;
public:
    Szerepkor(const string& Szerep_);
    string getSzerep() const;
    int getSzID() const;

};

#endif // SZEREPKOR_H
