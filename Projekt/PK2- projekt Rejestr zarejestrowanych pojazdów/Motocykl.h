#pragma once
#include "Pojazd.h"
class Motocykl : public Pojazd
{
private: 
	int pojemnoscSilnika;
	int mocSilnika;

public:
	Motocykl(const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel, int pojemnoscSilnika, int mocSilnika);
	void printInfo() const override;
	int getPojemnoscSilnika() const;
	int getMocSilnika() const;


};
