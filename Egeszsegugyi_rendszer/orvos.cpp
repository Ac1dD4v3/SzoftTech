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
        try{
        betegkiir.open("orvos_betegei.txt");
        if(betegkiir.is_open()){
            for(int i=0;i<Betegek.size();i++){
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<Betegek[i].getSzID()<<";"<<Betegek[i].getFelhNev()<<";"<<Betegek[i].getFelhJelszo()<<";"<<Betegek[i].getFelhEmail()<<";"<<Betegek[i].getTajSzam()<<"\n";
            }
        }
        }catch (const Hiba& e) {
        // Elkapjuk a saját exception-t és kiírjuk az üzenetét
        std::cout << "Hiba történt: " << e.what() << std::endl;
        }
        betegkiir.close();
        return Betegek;
    }

    void Orvos::betegTorlese(){
        //beolvasas
        vector<Beteg>betegek;
        ifstream input;
        input.open("orvos_betegei.txt");
        if(input.is_open()){
            string line, part;
            while (!input.eof()) {
                getline(input, line);
                if (line == "") continue;
                stringstream ss(line);
                string parts[6];
                int idx = 0;
                while (getline(ss, part, ';')) {
                        parts[idx++] = part;
                    }
                int tipus = stoi(parts[0]);
                int szid = stoi(parts[1]);
                string nev = parts[2];
                string jelszo = parts[3];
                string email = parts[4];
                int TAJ_szam = stoi(parts[5]);
                betegek.push_back(Beteg(szid,nev, jelszo, email, TAJ_szam));
            }
        }
        input.close();

        //kiiratas
        int szam=0;
        for(auto beteg : betegek){
            cout<<szam<<". "<<beteg.getSzID()<<" "<<beteg.getFelhNev()<<" "<<beteg.getFelhEmail()<<endl;
            szam++;
        }
        //valasztas
        int valasztott;
        cout<<"Kerlek valaszd ki a torlendo beteget es ird be a szamat: "<<endl;
        cin>>valasztott;
        for(int i=0;i<betegek.size();i++){
            if(valasztott==i){
                betegek.erase(betegek.begin()+i);
            }
        }

        //betegek tartalmának átadasa a Betegeknek
        Betegek=betegek;

        //file tartalmának törlése
        ofstream betegtorol;
        betegtorol.open("orvos_betegei.txt",std::ios_base::trunc);
        betegtorol.close();

        //fileba iras
        fstream betegkiir;
        betegkiir.open("orvos_betegei.txt",std::ios_base::app);
        if(betegkiir.is_open()){
            for(int i=0;i<Betegek.size();i++){
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<Betegek[i].getSzID()<<";"<<Betegek[i].getFelhNev()<<";"<<Betegek[i].getFelhJelszo()<<";"<<Betegek[i].getFelhEmail()<<";"<<Betegek[i].getTajSzam()<<"\n";
            }
        }
        betegkiir.close();
    }

    void Orvos::receptLetrehozasa()
    {
        //beolvasas
        vector<Beteg>betegek;
        ifstream input;
        input.open("orvos_betegei.txt");
        if(input.is_open()){
            string line, part;
            while (!input.eof()) {
                getline(input, line);
                if (line == "") continue;
                stringstream ss(line);
                string parts[6];
                int idx = 0;
                while (getline(ss, part, ';')) {
                        parts[idx++] = part;
                    }
                int tipus = stoi(parts[0]);
                int szid = stoi(parts[1]);
                string nev = parts[2];
                string jelszo = parts[3];
                string email = parts[4];
                int TAJ_szam = stoi(parts[5]);
                betegek.push_back(Beteg(szid,nev, jelszo, email, TAJ_szam));
            }
        }
        input.close();

        //sablon kitoltese
        cout<<"Kerem toltse ki a sablont"<<endl;
        string lejarati_datum,betegneve,orvosneve,gyogyszerneve;
        cout<<"Lejarati datum: ";
        cin>>lejarati_datum;

        int szam=0;
        for(auto beteg : betegek){
            cout<<szam<<" "<<beteg.getFelhNev()<<endl;
            szam++;
        }
        int valasztott;
        cout<<"Valassza ki a beteg nevet es irja be a szamat: "<<endl;
        cin>>valasztott;
        for(int i = 0; i<betegek.size() ; i++){
            if(valasztott==i){
                betegneve=betegek[i].getFelhNev();
            }
        }

        orvosneve=getFelhNev();

        cout<<"Gyogyszer neve: ";
        cin>>gyogyszerneve;

        Recept a(lejarati_datum,betegneve,orvosneve,gyogyszerneve);
        vector<Recept> receptek;
        receptek.push_back(a);
        HealthcareSystem::instance()->getBeteg(betegneve)->addF_Receptek(a);
        feladott_receptek.push_back(a);

        //kiiras fileba
        fstream receptkiir;
        receptkiir.open("orvos_altal_felirt_receptek.txt",std::ios_base::app);

        if(receptkiir.is_open()){
            for(auto recept : feladott_receptek){
                receptkiir<<recept.getBetegneve()<<";"<<recept.getGyogyszerneve()<<";"<<recept.getLejarati_datum()<<";"<<recept.getOrvosneve()<<"\n";
            }
        }
        receptkiir.close();
    }

    void Orvos::receptTorlese()
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
        for(int i=0;i<receptek.size();i++){
            cout<<szam<<". "<<receptek[i].getBetegneve()<<" "<<receptek[i].getGyogyszerneve()<<" "<<receptek[i].getLejarati_datum()<<endl;
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

        //betegek tartalmának átadasa a Betegeknek
//        vector<Recept> valosreceptek;
//        copy_if(receptek.begin(),receptek.end(),back_inserter(valosreceptek),[&receptek](){
//            auto it = find(receptek.begin(),receptek.end(),[](const Recept& recept){return recept;});
//            if(it==receptek.end()){
//                return true;
//            }
//        });
        feladott_receptek=receptek;

        //file tartalmának törlése
        ofstream recepttorol;
        recepttorol.open("orvos_altal_felirt_receptek.txt",std::ios_base::trunc);
        recepttorol.close();

        //kiiras fileba
        fstream receptkiir;
        receptkiir.open("orvos_altal_felirt_receptek.txt",std::ios_base::app);

        if(receptkiir.is_open()){
            for(int i=0;i<feladott_receptek.size();i++){
                receptkiir<<feladott_receptek[i].getBetegneve()<<";"<<feladott_receptek[i].getGyogyszerneve()<<";"<<feladott_receptek[i].getLejarati_datum()<<";"<<feladott_receptek[i].getOrvosneve()<<"\n";
            }
        }
        receptkiir.close();
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
            cout<<receptek.getBetegneve()<<" "<<receptek.getGyogyszerneve()<<" "<<receptek.getLejarati_datum()<<" "<<receptek.getOrvosneve()<<endl;
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
