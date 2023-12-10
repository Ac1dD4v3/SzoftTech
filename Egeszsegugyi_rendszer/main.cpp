#include <iostream>
#include <string>
#include <fstream>
#include "beteg.h"
#include "felhasznalo.h"
#include "gyogyszertar.h"
//#include "hiba.h"
#include "orvos.h"
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
        cout<<endl;
        orvosikezdolap(orvos);
    }

    else if(valasztas == 2){
        orvos->betegTorlese();
        system("CLS");
        cout<<"Beteg torolve a listarol"<<endl;
        cout<<endl;
        orvosikezdolap(orvos);
        //system("CLS");

    }
    else if(valasztas==3){
        orvos->receptLetrehozasa();
        system("CLS");
        cout<<"Recept hozzaadva a beteghez"<<endl;
        cout<<endl;
        orvosikezdolap(orvos);
    }
    else if(valasztas==4){
        orvos->receptTorlese();
        orvosikezdolap(orvos);
    }
    else{
        cout<<"Viszlat!"<<endl;
    }
}

void betegkezdolap(const BetegPtr& beteg){
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
        betegkezdolap(beteg);
    }
    else if(valasztas==1){
        beteg->receptIgenylese();
        betegkezdolap(beteg);
    }
    else if(valasztas==2){
        beteg->receptekMegtekintese();
        betegkezdolap(beteg);
    }
    else if(valasztas==3){
        cout<<"Recept igenylesehez irja be az 1-es szamot!"<<endl
            <<"Recept megtekintesehez irja be az 2-es szamot!"<<endl;
        betegkezdolap(beteg);
    }
    else{
        cout << "Viszlat!" << endl;
    }
}

void gyogyszertarkezdolap(const GyogyszertarPtr& gyogyszertar){
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
        gyogyszertarkezdolap(gyogyszertar);
    }
    else if(valasztas==1){
        cout<<"Recept torlese!"<<endl;
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
    else if (user->getTipus() == FelhasznaloTipus::BETEG) {
        auto beteg = std::dynamic_pointer_cast<Beteg>(user);
        if (!beteg) {
            throw "balfaszvagy";
        }
        betegkezdolap(beteg);
    }
    else if(user->getTipus() == FelhasznaloTipus::GYOGYSZERTAR) {
        auto gyogyszertar = std::dynamic_pointer_cast<Gyogyszertar>(user);
        if (!gyogyszertar) {
            throw "balfaszvagy";
        }
        gyogyszertarkezdolap(gyogyszertar);
    }
    return 0;
}

