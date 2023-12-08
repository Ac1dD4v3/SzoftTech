#include "orvos.h"
#include "HealthcareSystem.h"

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
        return Betegek;
    }

    void Orvos::betegTorlese(const string &betegNev){
        std::remove_if(Betegek.begin(),Betegek.end(),[&betegNev](const Beteg& beteg){return beteg.getFelhNev()==betegNev;});
    }

    void Orvos::receptLetrehozasa()
    {
        vector<Recept> ujreceptek;
        cout<<"Kerem toltse ki a sblont"<<endl;
        int lejarati_datum;
        string betegneve,orvosneve,gyogyszerneve;
        cout<<"Lejarati datum: ";
        cin>>lejarati_datum;
        cout<<"Valassza ki a beteg nevet es irja be: "<<endl;
        for(auto beteg : Betegek){
            cout<<beteg.getFelhNev()<<endl;
        }
        cin>>betegneve;
        orvosneve=getFelhNev();
        cout<<"Gyogyszer neve: ";
        cin>>gyogyszerneve;
        Recept a(lejarati_datum,betegneve,orvosneve,gyogyszerneve);
        ujreceptek.push_back(a);
        //ide jon majd a shared pointer a betegre vonatkozoan setReceptek(ujreceptek);
        feladott_receptek.insert(make_pair(betegneve,a));
    }

    void Orvos::receptTorlese()
    {
        for(auto recept : feladott_receptek){
            cout<<recept.second.getLejarati_datum()<<" "<<recept.second.getBetegneve()<<" "<<recept.second.getOrvosneve()<<" "<<recept.second.getGyogyszerneve()<<endl;
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
