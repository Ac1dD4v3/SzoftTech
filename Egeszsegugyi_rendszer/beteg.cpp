#include "beteg.h"
using namespace valami;


vector<Recept> Beteg::getReceptek() const
{
    return receptek;
}

void Beteg::setReceptek(const vector<Recept> &newReceptek)
{
    receptek = newReceptek;
}

Beteg::Beteg(int SzID,
             const string& nev_,
             const string &jelsz_,
             const string& email_,
             int TAJ_szam_):
    Felhasznalo(SzID,nev_,jelsz_,email_),
    TAJ_szam(TAJ_szam_)
{}

int Beteg::getTajSzam() const
{
    return TAJ_szam;
}

void Beteg::setTajSzam(int ujtaj)
{
    TAJ_szam=ujtaj;
}

void Beteg::receptIgenylese()
{
    ofstream igenyelreceptek;
    igenyelreceptek.open("igenyeltreceptek.txt");
    if(igenyelreceptek.is_open()){
        cout<<"Ird be a gyogyszer nevet: ";
        string gyogyszerneve;
        cin>>gyogyszerneve;
        igenyelreceptek<<getFelhNev()<<";"<<gyogyszerneve;
    }
    else{
        cout<<"Nem lehet megnyitni"<<endl;
    }
}

void Beteg::receptekMegtekintese()
{
    for(auto recept : receptek){
        cout<<recept.getLejarati_datum()<<" "<<recept.getOrvosneve()<<" "<<recept.getGyogyszerneve()<<endl;
    }
}
