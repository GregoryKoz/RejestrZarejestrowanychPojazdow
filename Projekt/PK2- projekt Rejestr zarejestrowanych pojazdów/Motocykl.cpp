#include "Motocykl.h"

Motocykl::Motocykl(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int pojemnoscSilnika, int mocSilnika)
    : Pojazd("Motocykl", marka, nazwa, nrRejestracyjny, wlasciciel), pojemnoscSilnika(pojemnoscSilnika), mocSilnika(mocSilnika) {}
