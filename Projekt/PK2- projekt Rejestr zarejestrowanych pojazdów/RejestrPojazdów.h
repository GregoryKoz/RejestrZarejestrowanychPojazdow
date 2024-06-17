#pragma once
#include "Pojazd.h"
#include <vector>
#include <iostream>
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
    void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku) const;
    void zapiszPojazdyWlasciciela(const std::string& imie, const std::string& nazwisko, const std::string& nazwaPliku) const;
    ~RejestrPojazdow();
};

