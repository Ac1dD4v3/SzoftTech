#include "orvos.h"

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
    system("CLS");
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
        cout<<"Beteg lista frissitve!"<<endl;
    }

    return Betegek;
}

vector<string> Orvos::betegTorlese(){
    vector<string> ujlista;
//    int szam=1;
//    for(size_t i=0;i<Betegek.size();i++){
//        cout<<szam<<": "<<Betegek[i]<<";"<<endl;
//        szam++;
//    }
//    cout<<"Beteg torolve"<<endl;
    return ujlista;
}

Orvos::Orvos(int SzID,
             const string &nev_,
             const string &jelsz_,
             const string &email_,
             const string &OTH_kod_):
    Felhasznalo(SzID,nev_,jelsz_,email_),
    OTH_kod(OTH_kod_)
{}
