#pragma once
#include "Pojazd.h"
class SamochodCiezarowy : public Pojazd
{
private:
	int ladownosc;
public:
	SamochodCiezarowy(const string& nazwa, const string& nr, const Wlasciciel& wl, int ladownosc);
	int getLadownosc()const;

};

