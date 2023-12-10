#include "orvos.h"
#include "HealthcareSystem.h"
using namespace std;
namespace valami {
    string Orvos::getOTH_kod() const
    {
        return OTH_kod;
    }

    void Orvos::setOTH_kod(const string &ujoth)
    {
        OTH_kod=ujoth;
    }

    vector<Beteg> Orvos::betegFelvetele()
    {
        vector<BetegPtr> ujlista = HealthcareSystem::instance()->getBetegek();
        
        int szam=0;
        for(auto beteg : ujlista){
            cout<<szam<<": "<<beteg->getSzID()<<" "<<beteg->getFelhNev()<<" "<<beteg->getFelhJelszo()<<" "<<beteg->getFelhEmail()<<" "<<beteg->getTajSzam()<<endl;
            szam++;
        }
        int kivalasztott;
        cout<<"Valaszd ki a beteget!"<<endl;
        cin>>kivalasztott;
        for(int i=0;i<=kivalasztott;i++){
            if(i==kivalasztott){
                Betegek.push_back(*(ujlista[i]));
            }
        }
        cout<<endl;
        fstream betegkiir;
        betegkiir.open("orvos_betegei.txt",std::ios_base::app);
        if(betegkiir.is_open()){
            for(auto beteg : Betegek){
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<beteg.getSzID()<<";"<<beteg.getFelhNev()<<";"<<beteg.getFelhEmail()<<";"<<beteg.getTajSzam()<<"\n";
            }
        }
        return Betegek;
    }

    void Orvos::betegTorlese(){
        //beolvasas
        vector<Beteg> ujlista;
        fstream betoltes;
        betoltes.open("orvos_betegei.txt");
        string line, part;
        while (!betoltes.eof()) {
            getline(betoltes, line);
            if (line == "") continue;
            stringstream ss(line);
            string parts[6];
            int idx = 0;
            while (getline(ss, part, ';')) {
                parts[idx++] = part;
            }
            string tipus = parts[0];
            int szid = stoi(parts[1]);
            string nev = parts[2];
            string jelszo = parts[3];
            string email = parts[4];
            int TAJ_szam = stoi(parts[5]);
            ujlista.push_back(Beteg(szid,nev, jelszo, email, TAJ_szam));
        }
        //kiiratas
        int szam=0;
        for(auto beteg : ujlista){
            cout<<szam<<". "<<beteg.getSzID()<<" "<<beteg.getFelhNev()<<" "<<beteg.getFelhEmail()<<endl;
            szam++;
        }
        //valasztas
        int valasztott;
        cout<<"Kerlek valaszd ki a torlendo beteget es ird be a szamat: "<<endl;
        cin>>valasztott;
        for(int i=0;i<Betegek.size();i++){
            if(valasztott==i){
                Betegek.erase(Betegek.begin()+i);
            }
        }
        ujlista=Betegek;
        //fileba iras
        fstream betegkiir;
        betegkiir.open("orvos_betegei.txt",std::ios_base::app);
        if(betegkiir.is_open()){
            for(auto beteg : Betegek){
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<beteg.getSzID()<<";"<<beteg.getFelhNev()<<";"<<beteg.getFelhEmail()<<";"<<beteg.getTajSzam()<<"\n";
            }
        }
    }

    void Orvos::receptLetrehozasa()
    {
        cout<<"Kerem toltse ki a sablont"<<endl;
        string lejarati_datum,betegneve,orvosneve,gyogyszerneve;
        cout<<"Lejarati datum: ";
        cin>>lejarati_datum;

        int szam=0;
        for(auto beteg : Betegek){
            cout<<szam<<" "<<beteg.getFelhNev()<<endl;
            szam++;
        }
        int valasztott;
        cout<<"Valassza ki a beteg nevet es irja be a szamat: "<<endl;
        cin>>valasztott;
        for(int i = 0; i<Betegek.size() ; i++){
            if(valasztott==i){
                betegneve=Betegek[i].getFelhNev();
            }
        }

        orvosneve=getFelhNev();

        cout<<"Gyogyszer neve: ";
        cin>>gyogyszerneve;

        Recept a(lejarati_datum,betegneve,orvosneve,gyogyszerneve);

        HealthcareSystem::instance()->getBeteg(betegneve)->addF_Receptek(a);
        feladott_receptek.insert(make_pair(betegneve,a));
    }

    void Orvos::receptTorlese()
    {
        int szam=0;
        for(auto recept : feladott_receptek){
            cout<<szam<<" "<<recept.second.getLejarati_datum()<<" "<<recept.second.getBetegneve()<<" "<<recept.second.getOrvosneve()<<" "<<recept.second.getGyogyszerneve()<<endl;
            szam++;
        }
        cout<<"Valaszd ki a receptet!"<<endl;

    }

    void Orvos::getBetegek() const
    {
        for(auto beteg : Betegek){
            cout<<beteg.getFelhNev()<<endl;
        }
    }

    void Orvos::getFeladott_receptek() const
    {
        for(auto receptek : feladott_receptek){
            cout<<receptek.first<<receptek.second<<endl;
        }
    }

    Orvos::Orvos(int SzID,
                const string &nev_,
                const string &jelsz_,
                const string &email_,
                const string &OTH_kod_):
        Felhasznalo(SzID,nev_,jelsz_,email_, FelhasznaloTipus::ORVOS),
        OTH_kod(OTH_kod_)
    {}
}
