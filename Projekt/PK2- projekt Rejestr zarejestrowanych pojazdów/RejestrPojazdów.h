#pragma once
#include "Pojazd.h"
#include <vector>
#include <iostream>
class RejestrPojazdow
{
private:
	std::vector<std::unique_ptr<Pojazd>> pojazdy;
  
public:
    string nazwaPliku;
    void dodajPojazd(std::unique_ptr<Pojazd> pojazd);
    void usunPojazd(const std::string& nrRejestracyjny);
    void wyswietlPojazdy() const;
    void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku) const;
    void zapiszPojazdyWlasciciela(const std::string& imie, const std::string& nazwisko, const std::string& nazwaPliku) const;
};

