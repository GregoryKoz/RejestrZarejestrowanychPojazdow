#include "ciezarowy.h"

SamochodCiezarowy::SamochodCiezarowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int ladownosc)
    : Pojazd("SamochodCiezarowy", marka, nazwa, nrRejestracyjny, wlasciciel), ladownosc(ladownosc) {}

void SamochodCiezarowy::printInfo() const {
    Pojazd::printInfo();
    std::cout << "Ladownosc: " << ladownosc << " kg" << std::endl;
    std::cout << std::endl;
}
int SamochodCiezarowy::getLadownosc() const {
    return ladownosc;
}
void SamochodCiezarowy::zapiszDoPliku(std::ofstream& plik) const {
    Pojazd::zapiszDoPliku(plik);  
    plik << "Maksymalna ladownosc: " << getLadownosc() << std::endl;
}

void SamochodCiezarowy::zapiszKoniec(std::ofstream& plik) const
{
    Pojazd::zapiszKoniec(plik);
    plik << ladownosc << std::endl;
}
