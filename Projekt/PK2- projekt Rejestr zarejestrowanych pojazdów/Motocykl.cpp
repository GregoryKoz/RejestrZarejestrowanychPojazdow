#include "Motocykl.h"

Motocykl::Motocykl(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int pojemnoscSilnika, int mocSilnika)
    : Pojazd("Motocykl", marka, nazwa, nrRejestracyjny, wlasciciel), pojemnoscSilnika(pojemnoscSilnika), mocSilnika(mocSilnika) {}

void Motocykl::printInfo() const {
    Pojazd::printInfo();
    std::cout << "Typ pojazdu: Motocykl" << std::endl;
    std::cout << "Pojemnosc silnika: " << pojemnoscSilnika << "cm^3" << std::endl;
    std::cout << "Moc silnika: " << mocSilnika << "KM" << std::endl;
    std::cout << std::endl;
}
