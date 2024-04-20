#pragma once
#include "Pojazd.h"
class ciezarowy : public Pojazd
{
private:
	int ladownosc;
public:
	ciezarowy(const string& nazwa, const string& nr, const Wlasciciel& wl, int ladownosc);
	int getLadownosc()const;

};

