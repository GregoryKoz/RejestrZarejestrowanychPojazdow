#pragma once
#include "Pojazd.h"

class SamochodCiezarowy : public Pojazd
{
private:
	int ladownosc;
public:
	SamochodCiezarowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int ladownosc);
	void printInfo() const override;
	int getLadownosc() const;
	void zapiszDoPliku(std::ofstream& plik) const;
	void zapiszKoniec(std::ofstream& plik) const;
};

