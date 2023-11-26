#include <iostream>
#include <string>
#include <fstream>

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

string belepes(){
    int szerepkornumber;
    cout<<"Valaszd ki a szerepkorod, es ird be a szamat: "<<endl;
    cout<<"Orvos: 1"<<endl<<"Beteg: 2"<<endl<<"Gyogyszertar: 3"<<endl;
    cin>>szerepkornumber;
    if(szerepkornumber>3 || szerepkornumber<1){
        cout<<"Nem megfelelo szerepkor"<<endl;
        belepes();
    }
    else if(szerepkornumber==1){
        return "Orvos";
    }
    else if(szerepkornumber==2){
        return "Beteg";
    }
    else if(szerepkornumber==3)
        return "Gyogyszertar";
}
//bekéri a felhasználótól, hogy milyen szerepkörben van és csak akkor engedi be, ha a felhasználó és a jelszó is megegyezik
int main()
{
    Orvos o1("","","","");
    Beteg b1("","","","");
    Gyogyszertar gy1("","","","");
    ifstream orvosinput;
    orvosinput.open("orvosinput.txt");
    if(!orvosinput.is_open()){
        //hiba osztaly
        cout<<"nem sikerult megnyitni"<<endl;
    }
    else{
        string nev, email, OTH_kod, jelszo;
        getline(orvosinput, nev);
        getline(orvosinput, email);
        getline(orvosinput, OTH_kod);
        getline(orvosinput, jelszo);
        o1.setFelhNev(nev);
        o1.setFelhEmail(email);
        o1.setFelhJelszo(jelszo);
        o1.setOTH_kod(OTH_kod);
        //beolvas és az o1-nek beállítja az értékeit
    }

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

    string szerepkor=belepes();
    cout<<szerepkor<<endl;
    string inputszoveg="exit";
    while(exit!=exit){
        cout<<"Most mi lesz?: "<<endl;
        cin>>inputszoveg;
    }
    return 0;
}

