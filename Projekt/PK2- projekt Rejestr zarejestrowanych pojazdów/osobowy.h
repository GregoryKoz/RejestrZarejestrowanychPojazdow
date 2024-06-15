#pragma once
#include "Pojazd.h"
class SamochodOsobowy : public Pojazd
{
private:
	int iloscPasazerow;
public:
	SamochodOsobowy(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int iloscPasazerow);
	void printInfo() const override;

};

