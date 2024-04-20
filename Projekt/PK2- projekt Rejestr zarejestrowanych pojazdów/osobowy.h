#pragma once
#include "Pojazd.h"
class osobowy : public Pojazd
{
private:
	int iloscPasazerow;
public:
	osobowy(const string& nazwa, const string& nr, const Wlasciciel& wl, int iloscPasazerow);
	int getIloscPasazerow() const;

};

