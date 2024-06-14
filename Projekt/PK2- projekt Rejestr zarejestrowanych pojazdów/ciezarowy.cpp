#include "ciezarowy.h"

SamochodCiezarowy::SamochodCiezarowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int ladownosc)
    : Pojazd("SamochodCiezarowy", marka, nazwa, nrRejestracyjny, wlasciciel), ladownosc(ladownosc) {}
