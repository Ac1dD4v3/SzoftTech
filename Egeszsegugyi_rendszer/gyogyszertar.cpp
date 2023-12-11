#include "gyogyszertar.h"
#include "HealthcareSystem.h"
namespace valami {

string Gyogyszertar::getOTH_kod() const
{
    return OTH_kod;
}

void Gyogyszertar::setOTH_kod(const string &newOTH_kod)
{
    OTH_kod = newOTH_kod;
}

void Gyogyszertar::receptTorlese()
{

}

void Gyogyszertar::listElerheto() const
{
    try{
        vector<GyogyszerPtr> lista = HealthcareSystem::instance()->getGyogyszerek();
        int szam=0;
        for(auto gyogyszer : lista){
            cout<<szam<<": "<<gyogyszer->getNev()<<" "<<gyogyszer->getLejarati_datum()<<" "<<gyogyszer->getFelhasznalasiUtmutato()<<endl;
            szam++;
        }
        for(auto gyogyszer : Elerhetok){
            cout<<szam<<": "<<gyogyszer.getNev()<<" "<<gyogyszer.getLejarati_datum()<<" "<<gyogyszer.getFelhasznalasiUtmutato()<<endl;
            szam++;
        }
    }catch (const Hiba& e) {
        // Elkapjuk a saját exception-t és kiírjuk az üzenetét
        std::cout << "Hiba történt: " << e.what() << std::endl;
    }
}

void Gyogyszertar::deleteElerheto()
{

}

vector<Gyogyszer> Gyogyszertar::addElerheto()
{
    vector<GyogyszerPtr> lista = HealthcareSystem::instance()->getGyogyszerek();
    int szam=0;
    for(auto gyogyszer : lista){
        cout<<szam<<": "<<gyogyszer->getNev()<<" "<<gyogyszer->getLejarati_datum()<<" "<<gyogyszer->getFelhasznalasiUtmutato()<<endl;
        szam++;
    }
    int kivalasztott;
    cout<<"Valaszd ki a gyogyszert!"<<endl;
    cin>>kivalasztott;
    for(int i=0;i<=kivalasztott;i++){
        if(i==kivalasztott){
            Elerhetok.push_back(*(lista[i]));
        }
    }
    cout<<endl;
    fstream gyogyszerkiir;
    gyogyszerkiir.open("elerheto_gyogyszerek.txt");
    if(gyogyszerkiir.is_open()){
        for(int i=0;i<Elerhetok.size();i++){
            gyogyszerkiir<<Elerhetok[i].getNev()<<";"<<Elerhetok[i].getLejarati_datum()<<";"<<Elerhetok[i].getFelhasznalasiUtmutato()<<"\n";
        }
    }
    gyogyszerkiir.close();
    return Elerhetok;
}

vector<Gyogyszer> Gyogyszertar::getElerhetok() const
{
    for(auto gyogyszer : Elerhetok){
        cout<<gyogyszer.getNev()<<" "<<gyogyszer.getLejarati_datum()<<endl;
    }
}

void Gyogyszertar::setElerhetok(const vector<Gyogyszer> &newElerhetok)
{
    Elerhetok = newElerhetok;
}

Gyogyszertar::Gyogyszertar(int SzID, const string &nev_,
                           const string &jelsz_,
                           const string &email_,
                           const string &OTH_kod_):
    Felhasznalo(SzID,nev_,jelsz_,email_, FelhasznaloTipus::GYOGYSZERTAR),
    OTH_kod(OTH_kod_)
{}

}
