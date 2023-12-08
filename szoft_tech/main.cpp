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

void orvosikezdolap(const OrvosPtr& orvos){
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
        orvosikezdolap(orvos);
    }
    else if(valasztas==1){
        orvos->betegFelvetele();
        system("CLS");
        cout<<"Beteg lista frissitve! Betg hozzaadva"<<endl;
        orvosikezdolap(orvos);
        //ide jönnek az osztalyok fuggvenyei
    }

    else if(valasztas == 2){
        orvos->getBetegek();
        cout<<"Kerlek ird be a beteg nevet: ";
        string nev;
        cin >> nev;
        orvos->betegTorlese(nev);
        orvosikezdolap(orvos);
        //system("CLS");

    }
    else if(valasztas==3){
        orvos->receptLetrehozasa();
    }
    else if(valasztas==4){
        orvos->receptTorlese();
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
        <<"2: Receptek megtekintese;"<<endl
        <<"3: Segitseg;"<<endl
        <<"4: Kilepes;"<<endl;
    cin>>valasztas;
    if(valasztas>4 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        betegkezdolap();
    }
    else if(valasztas==1){
        HealthcareSystem::instance()->getBeteg("Beteg")->receptIgenylese();
    }
    else if(valasztas==2){
        HealthcareSystem::instance()->getBeteg("Beteg")->receptekMegtekintese();
    }
    else if(valasztas==3){
        cout<<"Recept igenylesehez irja be az 1-es szamot!"<<endl;
        betegkezdolap();
    }
    else{
        cout << "Viszlat!" << endl;
    }
}

void gyogyszertarkezdolap(){
    int valasztas;
    cout<<endl;
    cout << "Valassz a lehetosegek kozul: "<<endl
        <<"1: Recept torlese;"<<endl
        <<"2: Elerheto gyogyszerek;"<<endl
        <<"3: Elerheto gyogyszer torlese;"<<endl
        <<"4: Elerheto gyogyszer hozzaadasa;"<<endl
        <<"5: Kilepes;"<<endl;
    cin>>valasztas;
    if(valasztas>5 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        gyogyszertarkezdolap();
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
    else if(valasztas==4){
        cout<<"Elerheto gyogyszer hozzaadva!"<<endl;
    }
    else{
        cout << "Viszlat!" << endl;
    }
}

int main()
{
    // szerepkorvalasztas();
    std::cout << "felhasznalonev: " << std::endl;
    string username;
    std::cin >> username;

    std::cout << "jelszo: " << std::endl;
    string pwd;
    std::cin >> pwd;
    auto user = HealthcareSystem::instance()->bejelentkezes(username, pwd);
    if (user->getTipus() == FelhasznaloTipus::ORVOS) {
        auto orvos = std::dynamic_pointer_cast<Orvos>(user);
        if (!orvos) {
            throw "balfaszvagy";
        }
        orvosikezdolap(orvos);
    }

    return 0;
}

