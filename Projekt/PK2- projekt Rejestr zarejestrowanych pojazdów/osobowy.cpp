#include "osobowy.h"

SamochodOsobowy::SamochodOsobowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int iloscPasazerow)
    : Pojazd("SamochodOsobowy", marka, nazwa, nrRejestracyjny, wlasciciel), iloscPasazerow(iloscPasazerow) {}

void SamochodOsobowy::printInfo() const {
    Pojazd::printInfo();
    std::cout << "Ilosc miejsc: " << iloscPasazerow << std::endl;
    std::cout << std::endl;
}
int SamochodOsobowy::getIloscPasazerow() const {
    return iloscPasazerow;
}