#include "recept.h"

Datum Recept::getLejaratiDatum() const
{
    return this->lejarati_datum;
}

string Recept::getBetegNeve() const
{
    return this->beteg_neve;
}

string Recept::getFeladoOrvos() const
{
    return this->felado_orvos;
}

string Recept::getGyogyszerNeve() const
{
    return this->gyogyszer_neve;
}
