#include "osobowy.h"

SamochodOsobowy::SamochodOsobowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int iloscPasazerow)
    : Pojazd("SamochodOsobowy", marka, nazwa, nrRejestracyjny, wlasciciel), iloscPasazerow(iloscPasazerow) {}
