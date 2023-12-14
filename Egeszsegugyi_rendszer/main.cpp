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
        <<"1: Betegek letrehozasa;"<<endl
        <<"2: Betegek listazasa;"<<endl
        <<"3: Beteg felvetele;"<<endl
        <<"4: Beteg torlese;"<<endl
        <<"5: Receptek listazasa;"<<endl
        <<"6: Recept letrehozasa;"<<endl
        <<"7: Recept torlese;"<<endl
        <<"8: Kilepes;"<<endl;
    cin>>valasztas;

    if(valasztas>8 || valasztas<1){
        cout<<"Nincs ilyen lehetoseg"<<endl;
        orvosikezdolap(orvos);
    }
    else if(valasztas==1){
        orvos->betegLetrehozas();
        cout<<endl;
        orvosikezdolap(orvos);
    }
    else if(valasztas==2){
        orvos->kiirBetegek();
        cout<<endl;
        orvosikezdolap(orvos);
    }
    else if(valasztas==3){
        orvos->betegFelvetele();
        system("CLS");
        cout<<"Beteg lista frissitve! Beteg hozzaadva"<<endl;
        cout<<endl;
        orvosikezdolap(orvos);
    }

    else if(valasztas == 4){
        orvos->betegTorlese();
        system("CLS");
        cout<<"Beteg torolve a listarol"<<endl;
        cout<<endl;
        orvosikezdolap(orvos);
        //system("CLS");

    }
    else if(valasztas == 5){
        orvos->kiirReceptek();
        cout<<endl;
        orvosikezdolap(orvos);
        //system("CLS");

    }
    else if(valasztas==6){
        orvos->receptLetrehozasa();
        system("CLS");
        cout<<"Recept hozzaadva a beteghez"<<endl;
        cout<<endl;
        orvosikezdolap(orvos);
    }
    else if(valasztas==7){
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
        gyogyszertar->receptTorlese();
        gyogyszertarkezdolap(gyogyszertar);
    }
    else if(valasztas==2){
        gyogyszertar->listElerheto();
        gyogyszertarkezdolap(gyogyszertar);
    }
    else if(valasztas==3){
        gyogyszertar->deleteElerheto();
        gyogyszertarkezdolap(gyogyszertar);
    }
    else if(valasztas==4){
        gyogyszertar->addElerheto();
        gyogyszertarkezdolap(gyogyszertar);
    }
    else{
        cout << "Viszlat!" << endl;
    }
}

int main()
{
    cout<<"Belepes: 1 | Beteg regisztarcio: 2"<<endl;
    int valasztas;
    cin>>valasztas;
    while(valasztas!=1 || valasztas!=2){
        if(valasztas==1){
            // szerepkorvalasztas();
            std::cout << "felhasznalonev: " << std::endl;
            string username;
            std::cin >> username;

            std::cout << "jelszo: " << std::endl;
            string pwd;
            std::cin >> pwd;
            auto user = HealthcareSystem::instance()->bejelentkezes(username, pwd);
            if (!user) {
                throw "Hibas felhasznalonev vagy jelszo";
            }
            if (user->getTipus() == FelhasznaloTipus::ORVOS) {
                auto orvos = std::dynamic_pointer_cast<Orvos>(user);
                if (!orvos) {
                    throw "balfaszvagy";
                }
                system("CLS");
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
        }
        else if(valasztas==2){
            vector<int> szemelyidk;
            ifstream input;
            input.open("felhasznalok.txt");
            if(!input.is_open()){
                //hiba osztaly
                cout<<"nem sikerult megnyitni"<<endl;
            }
            string line, part;
            while (!input.eof()) {
                getline(input, line);
                if (line == "") continue;
                stringstream ss(line);
                string parts[6];
                int idx = 0;
                while (getline(ss, part, ';')) {
                    parts[idx++] = part;
                }
                int tipus = stoi(parts[0]);
                int szid = stoi(parts[1]);
                string nev = parts[2];
                string jelszo = parts[3];
                string email = parts[4];
                int TAJ_szam = stoi(parts[5]);
                szemelyidk.push_back(szid);
            }



            int SzID, TAJ_szam;
            string nev,jelszav,email;
            cout<<"Szemelyid: ";
            cin>>SzID;
            auto it = find_if(szemelyidk.begin(),szemelyidk.end(),[SzID](int id){return SzID==id;});
            if(it!=szemelyidk.end()){
                cout<<"van mar ilyen id"<<endl;
                cout<<"Ezek mar foglaltak: "<<endl;
                for(auto id : szemelyidk){
                    cout<<id<<endl;
                }
            }
            else{
                cout<<"Nev: ";
                cin>>nev;
                cout<<"jelszo: ";
                cin>>jelszav;
                cout<<"Email: ";
                cin>>email;
                cout<<"TAJ_szam: ";
                cin>>TAJ_szam;
                ofstream betegkiir;
                betegkiir.open("felhasznalok.txt",std::ios_base::app);
                if(betegkiir.is_open()){
                    betegkiir<<"2;"<<SzID<<";"<<nev<<";"<<jelszav<<";"<<email<<";"<<TAJ_szam<<"\n";
                }
                betegkiir.close();
            }
        }
        else{
            cout<<"Nincs ilyen lehetoseg"<<endl;
        }
        cout<<"Belepes: 1 | Beteg regisztarcio: 2"<<endl;
        cin>>valasztas;
    }

    return 0;
}

