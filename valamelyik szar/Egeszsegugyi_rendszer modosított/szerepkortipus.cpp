#include "szerepkortipus.h"

Szerepkortipus::Szerepkortipus()
{

}

string Szerepkortipus::SzerepkorMegallapit()
{
    int szerepkornumber;
    cin >> szerepkornumber;
    if(szerepkornumber>3 || szerepkornumber<1){
        cout<<"Nem megfelelo szerepkor"<<endl;
        SzerepkorMegallapit();
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
