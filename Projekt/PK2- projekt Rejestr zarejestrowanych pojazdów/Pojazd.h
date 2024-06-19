#pragma once
#include <string>
#include <iostream>
#include "Wlasciciel.h"
using namespace std;
class Pojazd
{
protected:
	std::string typ;
	std::string marka;
	std::string nazwa;
	std::string nrRejestracyjny;
	Wlasciciel wlasciciel;
public:
	Pojazd(const std::string& typ, const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel);

	virtual void printInfo() const;
	virtual string getTyp() const;
	virtual string getMarka() const;
	virtual string getNazwa() const;
	virtual string getnrRejestracyjny() const;
	void ustawWlasciciela(const Wlasciciel& nowyWlasciciel);
	const Wlasciciel& getWlasciciel() const;
};

