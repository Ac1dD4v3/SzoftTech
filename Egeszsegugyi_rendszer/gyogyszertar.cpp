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
    //kiiratas
    int szam=0;
    for(auto recept : receptek){
        cout<<szam<<". "<<recept.getBetegneve()<<" "<<recept.getGyogyszerneve()<<" "<<recept.getLejarati_datum()<<endl;
        szam++;
    }
    //valasztas
    int valasztott;
    cout<<"Kerlek valaszd ki a torlendo receptet es ird be a szamat: "<<endl;
    cin>>valasztott;
    for(int i=0;i<receptek.size();i++){
        if(valasztott==i){
            receptek.erase(receptek.begin()+i);
        }
    }

    //file tartalmának törlése
    ofstream recepttorol;
    recepttorol.open("orvos_altal_felirt_receptek.txt",std::ios_base::trunc);
    recepttorol.close();

    //kiiras fileba
    fstream receptkiir;
    receptkiir.open("orvos_altal_felirt_receptek.txt",std::ios_base::app);

    if(receptkiir.is_open()){
        for(auto recept : receptek){
            receptkiir<<recept.getBetegneve()<<";"<<recept.getGyogyszerneve()<<";"<<recept.getLejarati_datum()<<";"<<recept.getOrvosneve()<<"\n";
        }
    }
    receptkiir.close();
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
    //beolvasas
    vector<Gyogyszer>gyogyszerek;
    ifstream input;
    input.open("elerheto_gyogyszerek.txt");
    if(input.is_open()){
        string line, part;
        while (!input.eof()) {
            getline(input, line);
            if (line == "") continue;
            stringstream ss(line);
            string parts[3];
            int idx = 0;
            while (getline(ss, part, ';')) {
                    parts[idx++] = part;
                }
            string nev = parts[0];
            string lejarati_datum = parts[1];
            string felhasznalasi = parts[2];
            gyogyszerek.push_back(Gyogyszer(nev,lejarati_datum, felhasznalasi));
        }
    }
    input.close();

    //kiiratas
    int szam=0;
    for(auto gyogyszer : gyogyszerek){
        cout<<szam<<". "<<gyogyszer.getNev()<<" "<<gyogyszer.getLejarati_datum()<<" "<<gyogyszer.getFelhasznalasiUtmutato()<<endl;
        szam++;
    }
    //valasztas
    int valasztott;
    cout<<"Kerlek valaszd ki a torlendo receptet es ird be a szamat: "<<endl;
    cin>>valasztott;
    for(int i=0;i<gyogyszerek.size();i++){
        if(valasztott==i){
            gyogyszerek.erase(gyogyszerek.begin()+i);
        }
    }

    //betegek tartalmának átadasa a Betegeknek
    Elerhetok=gyogyszerek;

    //file tartalmának törlése
    ofstream recepttorol;
    recepttorol.open("elerheto_gyogyszerek.txt",std::ios_base::trunc);
    recepttorol.close();

    //kiiras fileba
    fstream receptkiir;
    receptkiir.open("elerheto_gyogyszerek.txt",std::ios_base::app);

    if(receptkiir.is_open()){
        for(auto gyogyszer : Elerhetok){
            receptkiir<<gyogyszer.getNev()<<";"<<gyogyszer.getLejarati_datum()<<";"<<gyogyszer.getFelhasznalasiUtmutato()<<"\n";
        }
    }
    receptkiir.close();
}

void Gyogyszertar::addElerheto()
{
    //vector<GyogyszerPtr> ujlista = HealthcareSystem::instance()->getGyogyszerek();
    //beolvasas
    vector<Gyogyszer>gyogyszerek;
    ifstream input;
    input.open("gyogyszerek.txt");
    if(input.is_open()){
        string line, part;
        while (!input.eof()) {
            getline(input, line);
            if (line == "") continue;
            stringstream ss(line);
            string parts[3];
            int idx = 0;
            while (getline(ss, part, ';')) {
                    parts[idx++] = part;
                }
            string Nev = parts[0];
            string Lejarati_datum = parts[1];
            string FelhasznalasiUtmutato = parts[2];
            gyogyszerek.push_back(Gyogyszer(Nev,Lejarati_datum,FelhasznalasiUtmutato));
        }
    }

    input.close();

    //gyogyszerek kiirasa
    int szam=0;
    for(auto gyogyszer : gyogyszerek){
        cout<<szam<<". "<<gyogyszer.getNev()<<" "<<gyogyszer.getLejarati_datum()<<" "<<gyogyszer.getFelhasznalasiUtmutato()<<endl;
        szam++;
    }

    //kivalasztas
    int kivalasztott;
    cout<<"Valaszd ki a gyogyszert!"<<endl;
    cin>>kivalasztott;
    for(int i=0;i<=kivalasztott;i++){
        if(i==kivalasztott){
            Elerhetok.push_back(gyogyszerek[i]);
        }
    }
    //file tartalmának törlése
    ofstream gyogyszertorol;
    gyogyszertorol.open("elerheto_gyogyszerek.txt",std::ios_base::trunc);
    gyogyszertorol.close();

    //kiiras fileba
    fstream gyogyszerkiir;
    gyogyszerkiir.open("elerheto_gyogyszerek.txt",std::ios_base::app);
    if(gyogyszerkiir.is_open()){
        for(auto gyogyszer : Elerhetok){
            gyogyszerkiir<<gyogyszer.getNev()<<";"<<gyogyszer.getLejarati_datum()<<";"<<gyogyszer.getFelhasznalasiUtmutato()<<"\n";
        }
    }
    gyogyszerkiir.close();
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
