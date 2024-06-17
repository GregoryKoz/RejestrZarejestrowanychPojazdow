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
	string getTyp() const;
	string getMarka() const;
	string getNazwa() const;
	string getnrRejestracyjny() const;
};

