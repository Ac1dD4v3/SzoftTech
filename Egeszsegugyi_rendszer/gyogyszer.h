#ifndef GYOGYSZER_H
#define GYOGYSZER_H

#include <string>
#include <memory>
using namespace std;
    class Gyogyszer
    {
    private:
        string Nev;
        int Lejarati_datum;
        string FelhasznalasiUtmutato;
    public:
        Gyogyszer(const string& Nev, int Lejarati_datum, const string& FelhasznalasiUtmutato);
        string getNev() const;
        void setNev(const string &newNev);
        int getLejarati_datum() const;
        void setLejarati_datum(int newLejarati_datum);
        string getFelhasznalasiUtmutato() const;
        void setFelhasznalasiUtmutato(const string &newFelhasznalasiUtmutato);
    };
    typedef std::shared_ptr<Gyogyszer> GyogyszerPtr;
#endif // GYOGYSZER_H
