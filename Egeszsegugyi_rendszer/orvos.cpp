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

    const vector<BetegPtr>& Orvos::betegFelvetele()
    {
        if (!betegekBeolvasva) {
            getBetegek();
        }
        vector<BetegPtr> ujlista = HealthcareSystem::instance()->getBetegek();
        for (auto& beteg : Betegek) {
            auto it = ujlista.begin();
            for (; it != ujlista.end(); it++) {
                if (beteg->getSzID() == (*it)->getSzID()) {
                    break;
                }
            }

            if (it != ujlista.end()) {
                ujlista.erase(it);
            }
        }
        
        if (ujlista.empty()) {
            cout << "Honap dolgozoja!!! Osszes beteg felveve" << endl;
            return {};
        }

        int szam=0;
        for(auto& beteg : ujlista){
            cout<<szam<<": "<<beteg->getSzID()<<" "<<beteg->getFelhNev()<<" "<<beteg->getFelhJelszo()<<" "<<beteg->getFelhEmail()<<" "<<beteg->getTajSzam()<<endl;
            szam++;
        }
        int kivalasztott;
        cout<<"Valaszd ki a beteget!"<<endl;
        cin>>kivalasztott;
        if (kivalasztott >= 0 && kivalasztott < ujlista.size()) {
            Betegek.push_back(ujlista[kivalasztott]);
        }
        cout<<endl;
        fstream betegkiir;
        try{
        betegkiir.open("orvos_betegei.txt");
        if(betegkiir.is_open()){
            for(int i=0;i<Betegek.size();i++){
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<Betegek[i]->getSzID()<<";"<<Betegek[i]->getFelhNev()<<";"<<Betegek[i]->getFelhJelszo()<<";"<<Betegek[i]->getFelhEmail()<<";"<<Betegek[i]->getTajSzam()<<"\n";
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
        //kiiratas
        int szam=0;
        auto betegek = getBetegek();
        for(auto beteg : betegek){
            cout<<szam<<". "<<beteg->getSzID()<<" "<<beteg->getFelhNev()<<" "<<beteg->getFelhEmail()<<endl;
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
                betegkiir<<FelhasznaloTipus::BETEG<<";"<<Betegek[i]->getSzID()<<";"<<Betegek[i]->getFelhNev()<<";"<<Betegek[i]->getFelhJelszo()<<";"<<Betegek[i]->getFelhEmail()<<";"<<Betegek[i]->getTajSzam()<<"\n";
            }
        }
        betegkiir.close();
    }

    void Orvos::receptLetrehozasa()
    {
        //beolvasas
        auto betegek = getBetegek();

        //sablon kitoltese
        cout<<"Kerem toltse ki a sablont"<<endl;
        string lejarati_datum,betegneve,orvosneve,gyogyszerneve;
        cout<<"Lejarati datum: ";
        cin>>lejarati_datum;

        int szam=0;
        for(auto beteg : betegek){
            cout<<szam<<" "<<beteg->getFelhNev()<<endl;
            szam++;
        }
        int valasztott;
        cout<<"Valassza ki a beteg nevet es irja be a szamat: "<<endl;
        cin>>valasztott;
        for(int i = 0; i<betegek.size() ; i++){
            if(valasztott==i){
                betegneve=betegek[i]->getFelhNev();
            }
        }

        orvosneve=getFelhNev();

        cout<<"Gyogyszer neve: ";
        cin>>gyogyszerneve;

        auto a = std::make_shared<Recept>(lejarati_datum,betegneve,orvosneve,gyogyszerneve);
        vector<ReceptPtr> receptek;
        receptek.push_back(a);
        HealthcareSystem::instance()->getBeteg(betegneve)->addF_Receptek(a);
        feladott_receptek.push_back(a);

        //kiiras fileba
        fstream receptkiir;
        receptkiir.open("orvos_altal_felirt_receptek.txt");

        if(receptkiir.is_open()){
            for(auto recept : feladott_receptek){
                receptkiir<<(*recept)<<"\n";
            }
        }
        receptkiir.close();
    }

    void Orvos::receptTorlese()
    {
        //beolvasas
        auto receptek = getFeladottReceptek();
        
        //kiiratas
        int szam=0;
        for(int i=0;i<receptek.size();i++){
            cout<<szam<<". "<<receptek[i]->getBetegneve()<<" "<<receptek[i]->getGyogyszerneve()<<" "<<receptek[i]->getLejarati_datum()<<endl;
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

        feladott_receptek=receptek;

        //file tartalmának törlése
        ofstream receptkiir;
        receptkiir.open("orvos_altal_felirt_receptek.txt",std::ofstream::ate | std::ofstream::out);
        if(receptkiir.is_open()){
            for(int i=0;i<feladott_receptek.size();i++){
                receptkiir<<(*feladott_receptek[i])<<"\n";
            }
        }
        receptkiir.close();
    }

    const std::vector<BetegPtr>& Orvos::getBetegek()
    {
        if (betegekBeolvasva) return Betegek;

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
                Betegek.push_back(std::make_shared<Beteg>(szid,nev, jelszo, email, TAJ_szam));
            }
        }
        input.close();
        betegekBeolvasva = true;
        return Betegek;
    }

    void Orvos::kiirBetegek() {
        for(auto beteg : getBetegek()){
            cout<<beteg->getFelhNev()<<endl;
        }
    }

    const vector<ReceptPtr>& Orvos::getFeladottReceptek() {
        if (receptekBeolvasva) return feladott_receptek;

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
                feladott_receptek.push_back(std::make_shared<Recept>(datum, betegneve,orvosneve, gyogyszerneve));
            }
        }
        input.close();
        receptekBeolvasva = true;
        return feladott_receptek;
    }

    void Orvos::kiirReceptek()
    {
        for(auto receptek : getFeladottReceptek()){
            cout<<receptek->getBetegneve()<<" "<<receptek->getGyogyszerneve()<<" "<<receptek->getLejarati_datum()<<" "<<receptek->getOrvosneve()<<endl;
        }
    }

    void Orvos::betegLetrehozas()
    {
        vector<int> szemelyidk;
        ifstream input;
        input.open("felhasznalok.txt");
        if(!input.is_open()){
            //hiba osztaly
            cout<<"nem sikerult megnyitni"<<endl;
        }
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
            szemelyidk.push_back(szid);
        }



        int SzID, TAJ_szam;
        string nev,jelszav,email;
        cout<<"Szemelyid: ";
        cin>>SzID;
        auto it = find_if(szemelyidk.begin(),szemelyidk.end(),[SzID](int id){return SzID==id;});
        if(it!=szemelyidk.end()){
            cout<<"van mar ilyen id"<<endl;
            cout<<"Ezek mar foglaltak: "<<endl;
            for(auto id : szemelyidk){
                cout<<id<<endl;
            }
        }
        else{
            cout<<"Nev: ";
            cin>>nev;
            cout<<"jelszo: ";
            cin>>jelszav;
            cout<<"Email: ";
            cin>>email;
            cout<<"TAJ_szam: ";
            cin>>TAJ_szam;
            ofstream betegkiir;
            betegkiir.open("felhasznalok.txt",std::ios_base::app);
            if(betegkiir.is_open()){
                betegkiir<<"2;"<<SzID<<";"<<nev<<";"<<jelszav<<";"<<email<<";"<<TAJ_szam<<"\n";
            }
            betegkiir.close();
        }    }

    Orvos::Orvos(int SzID,
                const string &nev_,
                const string &jelsz_,
                const string &email_,
                const string &OTH_kod_):
        Felhasznalo(SzID,nev_,jelsz_,email_, FelhasznaloTipus::ORVOS),
        OTH_kod(OTH_kod_)
    {}
}
