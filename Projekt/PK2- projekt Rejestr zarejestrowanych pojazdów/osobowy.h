#pragma once
#include "Pojazd.h"
class SamochodOsobowy : public Pojazd
{
private:
	int iloscPasazerow;
public:
	SamochodOsobowy(const string& nazwa, const string& nr, const Wlasciciel& wl, int iloscPasazerow);
	int getIloscPasazerow() const;

};

