#include "RejestrPojazdów.h"
#include <fstream>


void RejestrPojazdow::dodajPojazd(Pojazd* pojazd) {
    pojazdy.push_back(pojazd);
}
void RejestrPojazdow::usunPojazd(const std::string& nrRejestracyjny) {
    bool usunieto = false;
    for (int i=0; i < pojazdy.size(); ++i) {
        if (pojazdy[i]->getnrRejestracyjny() == nrRejestracyjny) {
            delete pojazdy[i];
            pojazdy.erase(pojazdy.begin() + i);
            std::cout << "Usunieto pojazd o nr rejestracyjnym: " << nrRejestracyjny << std::endl;
            usunieto = true;
        }
    }
    if (!usunieto) {
        std::cout << "Nieznaleziono pojazdu o podanym numerze rejestracyjnym" << std::endl;
    }
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
void RejestrPojazdow::wypiszWlascicieli() const {
    for (const auto& w : wlasciciele) {
        w.printInfo();
    }
}
bool RejestrPojazdow::dodajWlasciciela(const Wlasciciel& wlasciciel) {
    for (const auto& w : wlasciciele) {
        if (w.getPesel() == wlasciciel.getPesel()) {
            return false; 
        }
    }
    wlasciciele.push_back(wlasciciel);
    return true; 
}
bool RejestrPojazdow::zmienWlasciciela(const std::string& nrRejestracyjny, const Wlasciciel& nowyWlasciciel) {
    for (Pojazd* pojazd : pojazdy) {
        if (pojazd->getnrRejestracyjny() == nrRejestracyjny) {
            pojazd->ustawWlasciciela(nowyWlasciciel);
            std::cout << "Wlasciciel pojazdu o numerze rejestracyjnym " << nrRejestracyjny << " zosta³ zmieniony." << std::endl;
            return true;
        }
    }
    std::cout << "Nie znaleziono pojazdu o numerze rejestracyjnym " << nrRejestracyjny << ". Sprawdz czy zostal prawidlowo podany." << std::endl;
    return false;
}
const std::vector<Pojazd*>& RejestrPojazdow::getPojazdy() const {
    return pojazdy;
}

void RejestrPojazdow::zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cout << "Nie mozna otworzyc pliku" << std::endl;
        return;
    }
    for (const auto& pojazd : pojazdy) {
        if (pojazd->getTyp() == typ) {
            plik << "Typ: " << pojazd->getTyp() << std::endl;
            plik << "Marka: " << pojazd->getMarka() << std::endl;
            plik << "Nazwa: " << pojazd->getNazwa() << std::endl;
            plik << "Numer rejestracyjny: " << pojazd->getnrRejestracyjny() << std::endl;
            plik << "Wlasciciel: " << pojazd->getWlasciciel().getImie()<< " " << pojazd->getWlasciciel().getNazwisko()<< " " << pojazd->getWlasciciel().getPesel() << std::endl;
            if (SamochodOsobowy* so = dynamic_cast<SamochodOsobowy*>(pojazd)) {
                plik << "Ilosc miejsc: " << so->getIloscPasazerow() << std::endl;
            }
            else if (SamochodCiezarowy* sc = dynamic_cast<SamochodCiezarowy*>(pojazd)) {
                plik << "Maksymalna ladownosc: " <<sc->getLadownosc() << std::endl;
            }
            else if (Motocykl* m = dynamic_cast<Motocykl*>(pojazd)) {
                plik << "Pojemnosc silnika: " << m->getPojemnoscSilnika() << std::endl;
                plik << "Moc silnika: " << m->getMocSilnika();
            }
            plik << std::endl;
        }
    }
}
void RejestrPojazdow::zapiszPojazdyWlasciciela(const std::string& pesel, const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cout << "Nie mozna otworzyc pliku." << std::endl;
        return;
    }
    Wlasciciel* wlasciciel = znajdzWlasciciela(pesel);
    if (!wlasciciel) {
        std::cout << "Taki wlasciciel nie istnieje." << std::endl;
        return;
    }
    else {
        plik << "Imie: " << wlasciciel->getImie() << std::endl;
        plik << "Nazwisko: " << wlasciciel->getNazwisko() << std::endl;
        plik << "Pesel: " << wlasciciel->getPesel() << std::endl;
        plik << "Pojazdy:" << std::endl;
        plik << std::endl;
        std::cout << "Zapisano dane do pliku " << nazwaPliku << std::endl;
    }
    for (const auto& pojazd : pojazdy) {
        if (pojazd->getWlasciciel().getPesel() == pesel) {
            plik << "Typ: " << pojazd->getTyp() << std::endl;
            plik << "Marka: " << pojazd->getMarka() << std::endl;
            plik << "Nazwa: " << pojazd->getNazwa() << std::endl;
            plik << "Numer rejestracyjny: " << pojazd->getnrRejestracyjny() << std::endl;
            if (SamochodOsobowy* so = dynamic_cast<SamochodOsobowy*>(pojazd)) {
                plik << "Ilosc miejsc: " << so->getIloscPasazerow() << std::endl;
            }
            else if (SamochodCiezarowy* sc = dynamic_cast<SamochodCiezarowy*>(pojazd)) {
                plik << "Maksymalna ladownosc: " << sc->getLadownosc() << std::endl;
            }
            else if (Motocykl* m = dynamic_cast<Motocykl*>(pojazd)) {
                plik << "Pojemnosc silnika: " << m->getPojemnoscSilnika() << std::endl;
                plik << "Moc silnika: " << m->getMocSilnika();
            }
            plik << std::endl; 
        }
    }

}