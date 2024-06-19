#pragma once
#include "Pojazd.h"
#include <vector>
#include <iostream>
#include "osobowy.h"
#include "Motocykl.h"
#include "ciezarowy.h"
class RejestrPojazdow
{
private:
	std::vector<Pojazd*> pojazdy;
    std::vector<Wlasciciel> wlasciciele;
  
public:
    string nazwaPliku;
    void dodajPojazd(Pojazd* pojazd);
    void usunPojazd(const std::string& nrRejestracyjny);
    void wyswietlPojazdy() const;
    Wlasciciel* znajdzWlasciciela(const std::string& pesel);
    void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku);
    void zapiszPojazdyWlasciciela(const std::string& pesel, const std::string& nazwaPliku);
    ~RejestrPojazdow();
    void wypiszWlascicieli() const;
    bool dodajWlasciciela(const Wlasciciel& wlasciciel);
    bool zmienWlasciciela(const std::string& nrRejestracyjny, const Wlasciciel& nowyWlasciciel);
    const std::vector<Pojazd*>& getPojazdy() const;
   
};

