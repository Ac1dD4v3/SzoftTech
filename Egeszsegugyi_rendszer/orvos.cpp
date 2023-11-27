#include "orvos.h"

string Orvos::getOTH_kod() const
{
    return OTH_kod;
}

void Orvos::setOTH_kod(const string &ujoth)
{
    OTH_kod=ujoth;
}

vector<string> Orvos::betegFelvetele()
{

    vector<string> ujlista;
    ifstream beteginput;
    beteginput.open("beteginput.txt");
    if(!beteginput.is_open()){
        //hiba osztaly
        cout<<"nem sikerult megnyitni"<<endl;
   }
    else{
//        string line, part;
//        while (!beteginput.eof()) {
//            getline(beteginput, line);
//            if (line != "") {
//                stringstream ss(line);
//                string parts[5];
//                int idx = 0;
//                while (getline(ss, part, ';')) {
//                    parts[idx++] = part;
//                }
//                int szid = stoi(parts[0]);
//                string nev = parts[1];
//                string jelszo = parts[2];
//                string email = parts[3];
//                int TAJ_szam = stoi(parts[4]);
//                Betegek.push_back(Beteg(nev, jelszo, email, TAJ_szam));
        string id;
        while (getline(beteginput, id,';')) {// Sorok beolvasása a fájlból
            stringstream ss(id);
            string cell;


            while (getline(ss, cell, ';')) { // Vesszővel elválasztott cellák feldolgozása
                ujlista.push_back(cell);
            }
        }
        beteginput.close(); // Fájl bezárása
        int szam=1;
        cout<<endl;
        for(size_t i=0;i<ujlista.size();i++){
            cout<<szam<<": "<<ujlista[i]<<endl;
            szam++;
        }
        cout<<"Valassza ki a beteget, akit szeretne a praxisaba felvenni es irja be a szamat!"<<endl;
        string valasztottbeteg;
        cin>>valasztottbeteg;
        Betegek.push_back(valasztottbeteg);
        cout<<"Beteg hozzaadva!"<<endl;
        return Betegek;
    }
}

vector<string> Orvos::betegTorlese(){
    vector<string> ujlista;
    int szam=1;
    for(size_t i=0;i<Betegek.size();i++){
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
