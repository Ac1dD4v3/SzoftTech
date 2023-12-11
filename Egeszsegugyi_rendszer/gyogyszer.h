#ifndef GYOGYSZER_H
#define GYOGYSZER_H

#include <string>
#include <memory>
using namespace std;
namespace valami{
    class Gyogyszer
    {
    private:
        string Nev;
        string Lejarati_datum;
        string FelhasznalasiUtmutato;
    public:
        Gyogyszer(const string& Nev, string Lejarati_datum, const string& FelhasznalasiUtmutato);
        string getNev() const;
        void setNev(const string &newNev);
        string getLejarati_datum() const;
        void setLejarati_datum(int newLejarati_datum);
        string getFelhasznalasiUtmutato() const;
        void setFelhasznalasiUtmutato(const string &newFelhasznalasiUtmutato);
    };
    typedef std::shared_ptr<Gyogyszer> GyogyszerPtr;
}
#endif // GYOGYSZER_H
