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

void orvosikezdolap(){
    Orvos o1("","","","");
    int valasztas;
    cout<<endl;
    cout << "Valassz a lehetosegek kozul: "<<endl
        <<"1: Beteg felvetele;"<<endl
        <<"2: Beteg torlese;"<<endl
        <<"3: Recept letrehozasa;"<<endl
        <<"4: Recept torlese;"<<endl;
    cin>>valasztas;
    if(valasztas>4 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        orvosikezdolap();
    }
    else if(valasztas==1){
        o1.betegFelvetele();
        orvosikezdolap();//ide jönnek az osztalyok fuggvenyei
    }
    else if(valasztas==2){
        o1.betegTorlese();
        orvosikezdolap();
    }
    else if(valasztas==3){
        //o1.receptLetrehozasa();
    }
    else{
        cout<<"Recept torolve!"<<endl;
    }
}

void betegkezdolap(){
    int valasztas;
    cout<<endl;
    cout << "Valassz a lehetosegek kozul: "<<endl
        <<"1: Recept igenylese;"<<endl
        <<"2: Segitseg;"<<endl;
    cin>>valasztas;
    if(valasztas>2 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        betegkezdolap();
    }
    else if(valasztas==1){
        cout<<"Recept igenyelve!"<<endl;
    }
    else{
        cout<<"Recept igenylesehez irja be az 1-es szamot!"<<endl;
        betegkezdolap();
    }
}

void gyogyszertarkezdolap(){
    int valasztas;
    cout<<endl;
    cout << "Valassz a lehetosegek kozul: "<<endl
        <<"1: Recept torlese;"<<endl
        <<"2: Elerheto gyogyszerek;"<<endl
        <<"3: Elerheto gyogyszer torlese;"<<endl
        <<"4: Elerheto gyogyszer hozzaadasa;"<<endl;
    cin>>valasztas;
    if(valasztas>4 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        orvosikezdolap();
    }
    else if(valasztas==1){
        cout<<"Recept torlese!"<<endl;//ide jönnek az osztalyok fuggvenyei
    }
    else if(valasztas==2){
        cout<<"Elerheto gyogyszerek: a b c!"<<endl;
    }
    else if(valasztas==3){
        cout<<"Elerheto gyogyszer torolve!"<<endl;
    }
    else{
        cout<<"Elerheto gyogyszer hozzaadva!"<<endl;
    }
}

void orvosibelepes(){
//    ifstream orvosinput;
//    orvosinput.open("orvosinput.txt");
//    if(!orvosinput.is_open()){
//        //hiba osztaly
//        cout<<"nem sikerult megnyitni"<<endl;
//    }
//    else{
//        string inputnev;
//        cout<<"Felhasznalonev: ";
//        cin>>inputnev;
//        string nev,jelszo;
//        int offset;
//        while(orvosinput.eof()){
//            if(offset=(nev.find(inputnev,0))!=string::npos){
//                getline(orvosinput,nev);
//                getline(orvosinput,jelszo);
//            }
//        }
//        cout<<nev<<jelszo<<endl;
//        orvosinput.close();
//    }
}
void betegbelepes(){}
void gyogyszertarbelepes(){}

void szerepkorvalasztas(){
    int szerepkornumber;
    cout<<"Valaszd ki a szerepkorod, es ird be a szamat: "<<endl;
    cout<<"Orvos: 1"<<endl<<"Beteg: 2"<<endl<<"Gyogyszertar: 3"<<endl;
    cin>>szerepkornumber;
    if(szerepkornumber>3 || szerepkornumber<1){
        cout<<"Nem megfelelo szerepkor"<<endl;
        szerepkorvalasztas();
    }
    else if(szerepkornumber==1){
        orvosibelepes();
        orvosikezdolap();
    }
    else if(szerepkornumber==2){

        //betegbelepes();
    }
    else if(szerepkornumber==3){
        //gyogyszertarbelepes();


        betegkezdolap();
    }
    else if(szerepkornumber==3){
        gyogyszertarkezdolap();
    }
}

int main()
{

//itt vannak a beolvasos kommentek
{

//    Orvos o1("","","","");
//    Beteg b1("","","","");
//    Gyogyszertar gy1("","","","");
//    ifstream orvosinput;
//    orvosinput.open("orvosinput.txt");
//    if(!orvosinput.is_open()){
//        //hiba osztaly
//        cout<<"nem sikerult megnyitni"<<endl;
//    }
//    else{
//        string nev, email, OTH_kod, jelszo;
//        getline(orvosinput, nev);
//        getline(orvosinput, email);
//        getline(orvosinput, OTH_kod);
//        getline(orvosinput, jelszo);
//        o1.setFelhNev(nev);
//        o1.setFelhEmail(email);
//        o1.setFelhJelszo(jelszo);
//        o1.setOTH_kod(OTH_kod);
//        //beolvas és az o1-nek beállítja az értékeit
//    }

//    ifstream beteginput;
//    beteginput.open("beteginput.txt");
//    if(!beteginput.is_open()){
//        //hiba osztaly
//        cout<<"nem sikerult megnyitni"<<endl;
//    }
//    else{
//        string nev, email, TAJ_szam, jelszo;
//        getline(beteginput,nev);
//        getline(beteginput,email);
//        getline(beteginput,TAJ_szam);
//        getline(orvosinput, jelszo);
//        b1.setFelhNev(nev);
//        b1.setFelhEmail(email);
//        b1.setTajSzam(TAJ_szam);
//        b1.setFelhJelszo(jelszo);
//    }

//    ifstream gyogyszertarinput;
//    gyogyszertarinput.open("gyogyszertarinput.txt");
//    if(!gyogyszertarinput.is_open()){
//        //hiba osztaly
//        cout<<"nem sikerult megnyitni"<<endl;
//    }
//    else{
//        string nev, email, OTH_kod, jelszo;
//        getline(gyogyszertarinput,nev);
//        getline(gyogyszertarinput,email);
//        getline(gyogyszertarinput,OTH_kod);
//        getline(orvosinput, jelszo);
//        gy1.setFelhNev(nev);
//        gy1.setFelhEmail(email);
//        gy1.setFelhJelszo(jelszo);
//        gy1.setOTH_kod(OTH_kod);
//    }
}
    szerepkorvalasztas();

    return 0;
}

