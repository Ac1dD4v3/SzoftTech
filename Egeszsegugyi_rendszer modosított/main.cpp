#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "beteg.h"
#include "datum.h"
#include "felhasznalo.h"
#include "felirtrecept.h"
#include "gyogyszer.h"
#include "gyogyszertar.h"
#include "hiba.h"
#include "orvos.h"
#include "recept.h"
#include "szerepkor.h"
#include "szerepkortipus.h"

using namespace std;

bool belepes(int SzID)
{
    string beirtFelhszNev, beirtJelszo;
    cout << "Irja be a felhasznalonevet : " << endl;
    cin >> beirtFelhszNev;
    if(SzID == 1)
    {

    }

}

void funkcióListaz_Orvos()
{
    cout<<"Orvosi belepés tortent, valasszon az opciok kozul: "<<endl;
    cout <<"1: Beteg felvetele" << endl << "2: Beteg torlese" << endl << "3: Recept letrehozasa" << endl << "4: Recept torlese" << endl;


}

void funkcióListaz_Beteg()
{
   cout<<"Beteg belepés tortent, valasszon az opciok kozul: "<<endl;
   cout << "1: Recept igenylese" << endl << "2: Segitseg" << endl;

}

void funkcióListaz_Gyogyszertar()
{
    cout<<"Gyogyszertari belepés tortent, valasszon az opciok kozul: "<<endl;
    cout << "1: Recept torlese" << endl << "2: Elerheto gyogyszerek listazasa" << endl << "3: Elerheto gyogyszer torlese" << endl << "4: Elerheto gyogyszer hozzaadasa" << endl;
}

//bekéri a felhasználótól, hogy milyen szerepkörben van és csak akkor engedi be, ha a felhasználó és a jelszó is megegyezik
int main()
{
    vector <Orvos> OrvosokAdatai;

    Orvos o1("","","","");
    Beteg b1("","","","");
    Gyogyszertar gy1("","","","");
    ifstream orvosinput;
    orvosinput.open("orvosinput.txt");

    if (!orvosinput.is_open()) {
        cout << "Nem sikerult megnyitni a fajlt." << endl;
    }
    else {
        string sor;
        while (getline(orvosinput, sor)) {
            istringstream tokenStream(sor);
            vector<string> tokens;
            string token;

            while (getline(tokenStream, token, ';')) {
                tokens.push_back(token);
            }

            if (tokens.size() == 4) {
                Orvos o(tokens[0], tokens[1], tokens[2], tokens[3]);
                OrvosokAdatai.push_back(o);
            }
        }

    // if(!orvosinput.is_open()){
    //     //hiba osztaly
    //     cout<<"nem sikerult megnyitni"<<endl;
    // }
    // else{
    //     string nev, email, OTH_kod, jelszo;
    //     getline(orvosinput, nev);
    //     getline(orvosinput, email);
    //     getline(orvosinput, OTH_kod);
    //     getline(orvosinput, jelszo);
    //     o1.setFelhNev(nev);
    //     o1.setFelhEmail(email);
    //     o1.setFelhJelszo(jelszo);
    //     o1.setOTH_kod(OTH_kod);
    //     //beolvas és az o1-nek beállítja az értékeit
    // }



    ifstream beteginput;
    beteginput.open("beteginput.txt");
    if(!beteginput.is_open()){
        //hiba osztaly
        cout<<"nem sikerult megnyitni"<<endl;
    }
    else{
        string nev, email, TAJ_szam, jelszo;
        getline(beteginput,nev);
        getline(beteginput,email);
        getline(beteginput,TAJ_szam);
        getline(orvosinput, jelszo);
        b1.setFelhNev(nev);
        b1.setFelhEmail(email);
        b1.setTajSzam(TAJ_szam);
        b1.setFelhJelszo(jelszo);
    }

    ifstream gyogyszertarinput;
    gyogyszertarinput.open("gyogyszertarinput.txt");
    if(!gyogyszertarinput.is_open()){
        //hiba osztaly
        cout<<"nem sikerult megnyitni"<<endl;
    }
    else{
        string nev, email, OTH_kod, jelszo;
        getline(gyogyszertarinput,nev);
        getline(gyogyszertarinput,email);
        getline(gyogyszertarinput,OTH_kod);
        getline(orvosinput, jelszo);
        gy1.setFelhNev(nev);
        gy1.setFelhEmail(email);
        gy1.setFelhJelszo(jelszo);
        gy1.setOTH_kod(OTH_kod);
    }

    // string szerepkor=belepes();
    // cout<<szerepkor<<endl;
    // string inputszoveg="exit";
    // while(exit!=exit){
    //     cout<<"Most mi lesz?: "<<endl;
    //     cin>>inputszoveg;
    // }

    //itt indul a szerep megállapítása

    Szerepkor::getSzerep();
    Szerepkor::getSzID();
    if(Szerepkor::getSzID() == 1)
    {
        if(belepes(int SzID))
        {
        funkcióListaz_Orvos();
        }
    }
    else if(Szerepkor::getSzID() == 2)
    {
        if(belepes(int SzID))
        {
        funkcióListaz_Beteg();
        }
    }
    else
    {
        if(belepes(int SzID))
        {
        funkcióListaz_Gyogyszertar();
        }
    }

    //itt indul a jelszavas kezelés és beléptetés

    return 0;
}
}
