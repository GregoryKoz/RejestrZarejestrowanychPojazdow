#include "RejestrPojazdów.h"


void RejestrPojazdow::dodajPojazd(Pojazd* pojazd) {
    pojazdy.push_back(pojazd);
}
void RejestrPojazdow::usunPojazd(const std::string& nrRejestracyjny) {
};
void RejestrPojazdow::wyswietlPojazdy() const {
    for (const auto& pojazd : pojazdy) {
        pojazd->printInfo();
    }
}
RejestrPojazdow::~RejestrPojazdow() {
    for (auto pojazd : pojazdy) {
        delete pojazd;
    }
}
Wlasciciel* RejestrPojazdow::znajdzWlasciciela(const std::string& pesel) {
    for (auto& w : wlasciciele) {
        if (w.getPesel() == pesel) {
            return &w;
        }
    }
    return nullptr;
}
//void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku) const;
//void zapiszPojazdyWlasciciela(const std::string& imie, const std::string& nazwisko, const std::string& nazwaPliku) const;