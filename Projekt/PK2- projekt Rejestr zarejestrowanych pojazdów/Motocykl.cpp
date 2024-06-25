#include "Motocykl.h"

Motocykl::Motocykl(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int pojemnoscSilnika, int mocSilnika)
    : Pojazd("Motocykl", marka, nazwa, nrRejestracyjny, wlasciciel), pojemnoscSilnika(pojemnoscSilnika), mocSilnika(mocSilnika) {}

void Motocykl::printInfo() const {
    Pojazd::printInfo();
    std::cout << "Pojemnosc silnika: " << pojemnoscSilnika << "cm^3" << std::endl;
    std::cout << "Moc silnika: " << mocSilnika << "KM" << std::endl;
    std::cout << std::endl;
}
int Motocykl::getPojemnoscSilnika() const {
    return pojemnoscSilnika;
}
    
int Motocykl::getMocSilnika() const {
    return mocSilnika;
}
void Motocykl::zapiszDoPliku(std::ofstream& plik) const {
    Pojazd::zapiszDoPliku(plik);  
    plik << "Pojemnosc silnika: " << getPojemnoscSilnika() << std::endl;
    plik << "Moc silnika: " << getMocSilnika() << std::endl;
}

void Motocykl::zapiszKoniec(std::ofstream& plik) const
{
    Pojazd::zapiszKoniec(plik);
    plik << pojemnoscSilnika << " " << mocSilnika << std::endl;
}
