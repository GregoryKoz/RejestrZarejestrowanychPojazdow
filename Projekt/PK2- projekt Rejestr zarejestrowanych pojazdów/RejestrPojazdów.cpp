#include "RejestrPojazdów.h"


void RejestrPojazdow::dodajPojazd(std::unique_ptr<Pojazd> pojazd) {
    pojazdy.push_back(std::move(pojazd));
}
void RejestrPojazdow::usunPojazd(const std::string& nrRejestracyjny) {};
void RejestrPojazdow::wyswietlPojazdy() const {
    for (const auto& pojazd : pojazdy) {
        pojazd->printInfo();
    }
}
//void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku) const;
//void zapiszPojazdyWlasciciela(const std::string& imie, const std::string& nazwisko, const std::string& nazwaPliku) const;