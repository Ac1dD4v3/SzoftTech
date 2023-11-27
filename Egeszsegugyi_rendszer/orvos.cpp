#include "orvos.h"

string Orvos::getOTH_kod() const
{
    return OTH_kod;
}

void Orvos::setOTH_kod(const string &ujoth)
{
    OTH_kod=ujoth;
}

void Orvos::betegFelvetele()
{
    vector<string> ujlista;
    ifstream beteginput;
    beteginput.open("beteginput.txt");
    if(!beteginput.is_open()){
        //hiba osztaly
        cout<<"nem sikerult megnyitni"<<endl;
   }
    else{
        string line;
        while (getline(beteginput, line)) { // Sorok beolvasása a fájlból
            stringstream ss(line);
            string cell;

            while (getline(ss, cell, ';')) { // Vesszővel elválasztott cellák feldolgozása
                Betegek.push_back(cell);
            }
        }

        beteginput.close(); // Fájl bezárása
        for(auto row:Betegek){
            cout<<row<<endl;
        }
    }
    cout<<"Beteg hozzaadva!"<<endl;
}

vector<string> Orvos::betegTorlese()
{
    vector<string> ujlista;
    int szam=1;
    for(int i=0;i<Betegek.size();i++){
        cout<<szam<<": "<<Betegek[i]<<";"<<endl;
        szam++;
    }
    cout<<"Beteg torolve"<<endl;
    return ujlista;
}

Orvos::Orvos(const string &nev_,
             const string &jelsz_,
             const string &email_,
             const string &OTH_kod_):
    Felhasznalo(nev_,jelsz_,email_),
    OTH_kod(OTH_kod_)
{}
