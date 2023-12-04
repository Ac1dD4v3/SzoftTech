#include <iostream>
#include <string>
#include <fstream>
#include "beteg.h"
//#include "datum.h"
#include "felhasznalo.h"
//#include "gyogyszer.h"
#include "gyogyszertar.h"
//#include "hiba.h"
#include "orvos.h"
//#include "recept.h"
#include "szerepkor.h"
#include "szerepkortipus.h"
#include "stdlib.h"
#include <memory>
#include "HealthcareSystem.h"

using namespace std;
using namespace valami;

void orvosikezdolap(){
    int valasztas;
    cout << "Valassz a lehetosegek kozul: "<<endl
        <<"1: Beteg felvetele;"<<endl
        <<"2: Beteg torlese;"<<endl
        <<"3: Recept letrehozasa;"<<endl
        <<"4: Recept torlese;"<<endl
        <<"5: Kilepes;"<<endl;
    cin>>valasztas;
    if(valasztas>5 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        orvosikezdolap();
    }
    else if(valasztas==1){
        HealthcareSystem::getOrvos("Semmelweis")->betegFelvetele();
        system("CLS");
        cout<<"Beteg lista frissitve! Betg hozzaadva"<<endl;
        orvosikezdolap();
        //ide jönnek az osztalyok fuggvenyei
    }
    else if(valasztas==2){
        HealthcareSystem::getOrvos("Semmelweis")->betegTorlese();
        system("CLS");
        cout<<"Beteg torolve"<<endl;
        orvosikezdolap();
    }
    else if(valasztas==3){
        //o1.receptLetrehozasa();
    }
    else if(valasztas==4){
        cout<<"Recept torolve!"<<endl;
    }
    else{
        cout<<"Viszlat!"<<endl;
    }
}

void betegkezdolap(){
    // system("CLS");
    int valasztas;
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

void orvosibelepes(){}
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
        //orvosibelepes();
        system("CLS");
        orvosikezdolap();
    }
    else if(szerepkornumber==2){
        //betegbelepes();
        // system("CLS");
        betegkezdolap();
    }
    else if(szerepkornumber==3){
        //gyogyszertarbelepes();
        // system("CLS");
        gyogyszertarkezdolap();
    }
}

int main()
{
    auto sys = std::make_shared<HealthcareSystem>();
    szerepkorvalasztas();

    return 0;
}

