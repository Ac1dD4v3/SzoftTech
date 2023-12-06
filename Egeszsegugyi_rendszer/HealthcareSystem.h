#ifndef __HEALTHCARE_H
#define __HEALTHCARE_H

#include "felhasznalo.h"
#include "orvos.h"

namespace valami {

    class HealthcareSystem {

        public:
            typedef std::shared_ptr<Felhasznalo> FelhasznaloPtr;

            HealthcareSystem() {
                //Todo beolvasni a listát
                
                // ha az orvos.txt-bol olvasod
                felhasznalok.push_back(std::make_shared<Orvos>(1, "Semmelweis","","",""));

                // ha a beteg.txt-bol olvasod
                felhasznalok.push_back(std::make_shared<Beteg>(1,"Beteg","","",1));
            }
            virtual ~HealthcareSystem() {}

            static OrvosPtr getOrvos(const std::string& nev) {
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev](const FelhasznaloPtr& user) { return user->getFelhNev() == nev; } );
                if (user != felhasznalok.end()) {
                    return std::dynamic_pointer_cast<Orvos>(*user);
                }
                return nullptr;
            }
            static BetegPtr getBeteg(const std::string& nev) {
                auto user = std::find_if(felhasznalok.begin(), felhasznalok.end(), [&nev](const FelhasznaloPtr& user) { return user->getFelhNev() == nev; } );
                if (user != felhasznalok.end()) {
                    return std::dynamic_pointer_cast<Beteg>(*user);
                }
                return nullptr;
            }

        private:
            static std::vector<FelhasznaloPtr> felhasznalok;
    };

}
#endif
