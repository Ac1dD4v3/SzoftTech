#include "beteg.h"
#include <algorithm>
#include "HealthcareSystem.h"
using namespace valami;


vector<Recept> Beteg::getF_Receptek() const
{
    return orvosaltal_receptek;
}

void Beteg::addF_Receptek(const Recept& recept)
{
    orvosaltal_receptek.push_back(recept);
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
            igenyelreceptek<<getFelhNev()<<";"<<gyogyszerneve<<"\n";
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
    //beolvasas
    vector<Recept>receptek;
    ifstream input;
    input.open("orvos_altal_felirt_receptek.txt");
    if(input.is_open()){
        string line, part;
        while (!input.eof()) {
            getline(input, line);
            if (line == "") continue;
            stringstream ss(line);
            string parts[4];
            int idx = 0;
            while (getline(ss, part, ';')) {
                    parts[idx++] = part;
                }
            string betegneve = parts[0];
            string gyogyszerneve = parts[1];
            string datum = parts[2];
            string orvosneve = parts[3];
            receptek.push_back(Recept(betegneve,gyogyszerneve, datum, orvosneve));
        }
    }
    input.close();

    //a megfelelő receptek áttöltese
    for(auto recept : receptek){
        cout<<recept.getBetegneve()<<" "<<recept.getGyogyszerneve()<<" "<<recept.getLejarati_datum()<<" "<<recept.getOrvosneve()<<endl;
        cout<<endl;
    }
//    vector<Recept> tmp;
//    string nev = this->getFelhNev();
//    cout<<nev<<endl;
//    for(int i = 0; i< receptek.size();i++){
//        if(receptek[i].getBetegneve()==nev){
//            tmp.push_back(receptek[i]);
//        }
//    }
//    //kiiratas
//    if (!tmp.empty()) {
//        int szam = 0;
//        for (const auto& recept : tmp) {
//            cout << szam << ". " << recept.getBetegneve() << " " << recept.getGyogyszerneve() << " " << recept.getLejarati_datum() << endl;
//            szam++;
//        }
//    } else {
//        cout << "Nincsenek elemek a listaban." << endl;
//    }

}
