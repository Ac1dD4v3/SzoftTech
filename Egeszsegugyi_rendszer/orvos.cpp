#include "orvos.h"

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
        vector<Beteg> ujlista;
        ifstream beteginput;

        beteginput.open("beteginput.txt");
        if(!beteginput.is_open()){
            //hiba osztaly
            cout<<"nem sikerult megnyitni"<<endl;
        }

        else{
            string line, part;
            while (!beteginput.eof()) {
                getline(beteginput, line);
                if (line != "") {
                    stringstream ss(line);
                    string parts[5];
                    int idx = 0;
                    while (getline(ss, part, ';')) {
                        parts[idx++] = part;
                    }
                    int szid = stoi(parts[0]);
                    string nev = parts[1];
                    string jelszo = parts[2];
                    string email = parts[3];
                    int TAJ_szam = stoi(parts[4]);
                    ujlista.push_back(Beteg(szid,nev, jelszo, email, TAJ_szam));

                }
            }
            int szam=0;
            for(auto beteg : ujlista){
                cout<<szam<<": "<<beteg.getSzID()<<" "<<beteg.getFelhNev()<<" "<<beteg.getFelhJelszo()<<" "<<beteg.getFelhEmail()<<" "<<beteg.getTajSzam()<<endl;
                szam++;
            }
            int kivalasztott;
            cout<<"Valaszd ki a beteget!"<<endl;
            cin>>kivalasztott;
            for(int i=0;i<=kivalasztott;i++){
                if(i==kivalasztott){
                    Betegek.push_back(ujlista[i]);
                }
            }
            cout<<endl;
        }
        return Betegek;
    }

    vector<Beteg> Orvos::betegTorlese(){
        size_t meret=Betegek.size();
        int szam=0;
        for(size_t i=0;i<Betegek.size();i++){
            cout<<szam<<" "<<Betegek[i].getFelhNev()<<";"<<endl;
            szam++;
        }
        int valasztott;
        cin>>valasztott;
        for(int i=0;i<Betegek.size();i++){
            if(valasztott==i);
        }
        for(size_t i=0;i<Betegek.size();i++){
            cout<<i<<": "<<Betegek[i].getFelhNev()<<";"<<endl;
        }
        if(Betegek.size()<meret){
            cout<<"Beteg torolve"<<endl;
        }
        return Betegek;
    }

    Orvos::Orvos(int SzID,
                const string &nev_,
                const string &jelsz_,
                const string &email_,
                const string &OTH_kod_):
        Felhasznalo(SzID,nev_,jelsz_,email_),
        OTH_kod(OTH_kod_)
    {}
}
