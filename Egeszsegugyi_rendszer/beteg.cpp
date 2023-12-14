#include "beteg.h"
#include <algorithm>
#include "HealthcareSystem.h"
using namespace valami;


const vector<ReceptPtr>& Beteg::getF_Receptek() const
{
    return orvosaltal_receptek;
}

void Beteg::addF_Receptek(const ReceptPtr& recept)
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
    vector<ReceptPtr>receptek;
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
            receptek.push_back(std::make_shared<Recept>(datum, betegneve, orvosneve, gyogyszerneve));
        }
    }
    input.close();

    //a megfelelő receptek áttöltese
    string nev = getFelhNev();
    copy_if(receptek.begin(),receptek.end(),back_inserter(orvosaltal_receptek),[&nev](const ReceptPtr& recept){return recept->getBetegneve()==nev;});

    //kiiratas
    int szam = 0;
    for (auto recept : orvosaltal_receptek) {
        cout << szam <<", Recept lejaratanak datuma: " << recept->getLejarati_datum() << ", A felado orvos neve: " << recept->getOrvosneve() << ", Gyogyszer: " << recept->getGyogyszerneve() << endl;
        szam++;
    }
}
