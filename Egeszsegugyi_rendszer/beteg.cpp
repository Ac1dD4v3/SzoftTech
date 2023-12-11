#include "beteg.h"
using namespace valami;


vector<Recept> Beteg::getF_Receptek() const
{
    return f_receptek;
}

void Beteg::addF_Receptek(const Recept& recept)
{
    f_receptek.push_back(recept);
}

Beteg::Beteg(int SzID,
             const string& nev_,
             const string &jelsz_,
             const string& email_,
             int TAJ_szam_):
    Felhasznalo(SzID,nev_,jelsz_,email_, FelhasznaloTipus::BETEG),
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
    try{
        ofstream igenyelreceptek;
        igenyelreceptek.open("igenyeltreceptek.txt", std::ios_base::app);
        if(igenyelreceptek.is_open()){
            cout<<"Ird be a gyogyszer nevet: ";
            string gyogyszerneve;
            cin>>gyogyszerneve;
            igenyelreceptek<<getFelhNev()<<";"<<gyogyszerneve;
        }
        else{
            throw Hiba("Nem nyilik meg");
        }
    }catch (const Hiba& e) {
            // Elkapjuk a saját exception-t és kiírjuk az üzenetét
            std::cout << "Hiba történt: " << e.what() << std::endl;
        }
}

void Beteg::receptekMegtekintese()
{
    for(auto recept : f_receptek){
        cout<<recept.getLejarati_datum()<<" "<<recept.getOrvosneve()<<" "<<recept.getGyogyszerneve()<<endl;
    }
}
