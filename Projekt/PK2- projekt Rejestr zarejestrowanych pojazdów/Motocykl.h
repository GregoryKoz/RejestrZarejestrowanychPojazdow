#pragma once
#include "Pojazd.h"
class Motocykl : public Pojazd
{
private: 
	int pojemnoscSilnika;
	int mocSilnika;

public:
	Motocykl(const string& nazwa, const string& nr, const Wlasciciel& wl, int pojemnoscSilnika, int mocSilnika);
	int getPojemnosc() const;
	int getMoc() const;

};

