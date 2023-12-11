#include "recept.h"
using namespace valami;
string Recept::getLejarati_datum() const
{
    return lejarati_datum;
}

void Recept::setLejarati_datum(string newLejarati_datum)
{
    lejarati_datum = newLejarati_datum;
}

string Recept::getBetegneve() const
{
    return betegneve;
}

void Recept::setBetegneve(const string &newBetegneve)
{
    betegneve = newBetegneve;
}

string Recept::getOrvosneve() const
{
    return orvosneve;
}

void Recept::setOrvosneve(const string &newOrvosneve)
{
    orvosneve = newOrvosneve;
}


string Recept::getGyogyszerneve() const
{
    return gyogyszerneve;
}

void Recept::setGyogyszerneve(const string &newGyogyszerneve)
{
    gyogyszerneve = newGyogyszerneve;
}

Recept::Recept(const string& lejarati_datum, const string &betegneve, const string &orvosneve, const string &gyogyszerneve):
    lejarati_datum(lejarati_datum),
    betegneve(betegneve),
    orvosneve(orvosneve),
    gyogyszerneve(gyogyszerneve)
{}
