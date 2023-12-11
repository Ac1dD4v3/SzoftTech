#ifndef GYOGYSZERTAR_H
#define GYOGYSZERTAR_H

#include <list>
#include "felhasznalo.h"
#include "orvos.h"
#include <memory>
#include "gyogyszer.h"
namespace valami{
    class Gyogyszertar : public Felhasznalo
    {
    private:
        string OTH_kod;
        vector<Gyogyszer> Elerhetok;
    public:
        Gyogyszertar(int SzID,const string &nev_, const string &jelsz_, const string &email_, const string& OTH_kod_);
        string getOTH_kod() const;

        void setOTH_kod(const string &newOTH_kod);
        void receptTorlese();
        void listElerheto()const;
        void deleteElerheto();
        void addElerheto();
        vector<Gyogyszer> getElerhetok() const;
        void setElerhetok(const vector<Gyogyszer> &newElerhetok);
    };
    typedef std::shared_ptr<Gyogyszertar> GyogyszertarPtr;
}
#endif // GYOGYSZERTAR_H
