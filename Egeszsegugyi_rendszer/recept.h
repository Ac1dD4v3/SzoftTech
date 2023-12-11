#ifndef RECEPT_H
#define RECEPT_H

#include <iostream>
#include <string>
#include <ostream>

#include "datum.h"

using namespace std;
namespace valami {
    class Recept
    {
    private:
        string lejarati_datum;
        string betegneve,orvosneve,gyogyszerneve;
    public:
        Recept(const string& lejarati_datum,const string& betegneve,const string& orvosneve,const string& gyogyszerneve);
        string getLejarati_datum() const;
        void setLejarati_datum(string newLejarati_datum);
        string getBetegneve() const;
        void setBetegneve(const string &newBetegneve);
        string getOrvosneve() const;
        void setOrvosneve(const string &newOrvosneve);
        friend ostream& operator<<(ostream& os,const Recept& recept){
            os<<recept.getLejarati_datum()<<";"<<recept.getBetegneve()<<";"<<recept.getOrvosneve()<<";"<<recept.getGyogyszerneve();
            return os;
        }
        string getGyogyszerneve() const;
        void setGyogyszerneve(const string &newGyogyszerneve);
    };
}
#endif // RECEPT_H
