#ifndef __HEALTHCARE_H
#define __HEALTHCARE_H

#include "felhasznalo.h"
#include "orvos.h"
#include "gyogyszertar.h"
#include "gyogyszer.h"

namespace valami {

    class HealthcareSystem {

        public:
            typedef std::shared_ptr<Felhasznalo> FelhasznaloPtr;

            static HealthcareSystem* instance() {
                if (!m_instance) {
                    m_instance = new HealthcareSystem();
                }
                return m_instance;
            }

            virtual ~HealthcareSystem() {
                delete m_instance;
            }

            OrvosPtr getOrvos(const std::string& nev) {
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev](const FelhasznaloPtr& user) { return user->getFelhNev() == nev; } );
                if (user != felhasznalok.end()) {
                    return std::dynamic_pointer_cast<Orvos>(*user);
                }
                return nullptr;
            }

            BetegPtr getBeteg(const std::string& nev) {
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev](const FelhasznaloPtr& user) { return user->getFelhNev() == nev; } );
                if (user != felhasznalok.end()) {
                    return std::dynamic_pointer_cast<Beteg>(*user);
                }
                return nullptr;
            }
            GyogyszertarPtr getGyogyszertar(const std::string& nev) {
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev](const FelhasznaloPtr& user) { return user->getFelhNev() == nev; } );
                if (user != felhasznalok.end()) {
                    return std::dynamic_pointer_cast<Gyogyszertar>(*user);
                }
                return nullptr;
            }


            std::vector<BetegPtr> getBetegek() {
                std::vector<FelhasznaloPtr> betegUsers;
                std::copy_if(felhasznalok.begin(), felhasznalok.end(), std::back_inserter(betegUsers), [](const FelhasznaloPtr& user) { return user->getTipus() == FelhasznaloTipus::BETEG; });
                std::vector<BetegPtr> betegek;
                std::transform(betegUsers.begin(), betegUsers.end(), std::back_inserter(betegek), [](const FelhasznaloPtr& ptr) {  return std::dynamic_pointer_cast<Beteg>(ptr); });
                return betegek;
            }

            std::vector<GyogyszerPtr> getGyogyszerek() {
                std::vector<GyogyszerPtr> gyogyszersz;
                std::transform(gyogyszerek.begin(), gyogyszerek.end(), std::back_inserter(gyogyszersz), [](const GyogyszerPtr& ptr) {  return std::dynamic_pointer_cast<Gyogyszer>(ptr); });
                return gyogyszerek;
            }

            FelhasznaloPtr bejelentkezes(const std::string& nev, const std::string& pwd) {
                // ellenorzes blabla
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev, &pwd](const FelhasznaloPtr& user) { return user->getFelhNev() == nev && user->getFelhJelszo() == pwd; } );
                if (user != felhasznalok.end()) {
                    activeUser = *user;
                    return *user;
                }
                return nullptr;
            }

            const FelhasznaloPtr& getActiveUser() const {
                return activeUser;
            }

        private:
            HealthcareSystem() {
                ifstream input;
                input.open("felhasznalok.txt");
                if(!input.is_open()){
                    //hiba osztaly
                    cout<<"nem sikerult megnyitni"<<endl;
                    return;
                }

                string line, part;
                while (!input.eof()) {
                    getline(input, line);
                    if (line == "") continue;

                    stringstream ss(line);
                    string tipusStr;
                    getline(ss, tipusStr, ';');
                    int tipus = stoi(tipusStr);
                    if (tipus == FelhasznaloTipus::BETEG) {
                        string parts[5];
                        int idx = 0;
                        while (getline(ss, part, ';')) {
                            parts[idx++] = part;
                        }
                        int szid = stoi(parts[0]);
                        string nev = parts[1];
                        string jelszo = parts[2];
                        string email = parts[3];
                        int TAJ_szam = stoi(parts[4]);
                        felhasznalok.push_back(std::make_shared<Beteg>(szid,nev, jelszo, email, TAJ_szam));
                    } else if (tipus == FelhasznaloTipus::GYOGYSZERTAR) {
                        string parts[5];
                        int idx = 0;
                        while (getline(ss, part, ';')) {
                            parts[idx++] = part;
                        }
                        int szid = stoi(parts[0]);
                        string nev = parts[1];
                        string jelszo = parts[2];
                        string email = parts[3];
                        string oth = parts[4];
                        felhasznalok.push_back(std::make_shared<Gyogyszertar>(szid,nev, jelszo, email, oth));
                    } else if (tipus == FelhasznaloTipus::ORVOS) {
                        string parts[5];
                        int idx = 0;
                        while (getline(ss, part, ';')) {
                            parts[idx++] = part;
                        }
                        int szid = stoi(parts[0]);
                        string nev = parts[1];
                        string jelszo = parts[2];
                        string email = parts[3];
                        string oth = parts[4];
                        felhasznalok.push_back(std::make_shared<Orvos>(szid,nev, jelszo, email, oth));
                    } else {
                        std::cout << "Nem ismert felhasznalo tipus '" << tipus << "'" << std::endl;
                    }
                }
            {
                ifstream gyogyszerinput;
                gyogyszerinput.open("gyogyszerek.txt");
                if(!gyogyszerinput.is_open()){
                    //hiba osztaly
                    cout<<"nem sikerult megnyitni"<<endl;
                    return;
                }
                    string line, part;
                    while (!input.eof()) {
                        getline(input, line);
                        if (line == "") continue;
                        stringstream ss(line);
                            string parts[3];
                            int idx = 0;
                            while (getline(ss, part, ';')) {
                                parts[idx++] = part;
                            }
                            string Nev = parts[0];
                            string Lejarati_datum = parts[1];
                            string FelhasznalasiUtmutato = parts[2];
                            gyogyszerek.push_back(std::make_shared<Gyogyszer>(Nev, Lejarati_datum,FelhasznalasiUtmutato));
                        }
                    }
            }

            std::vector<GyogyszerPtr> gyogyszerek;
            std::vector<FelhasznaloPtr> felhasznalok;
            FelhasznaloPtr activeUser;
            static HealthcareSystem* m_instance;
    };

}
#endif
