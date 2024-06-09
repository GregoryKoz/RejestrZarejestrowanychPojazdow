#pragma once
#include <string>
#include "Wlasciciel.h"
using namespace std;
class Pojazd
{
protected:
	string nazwa;
	string nrRejestracyjny;
	Wlasciciel wlasciciel;
public:
	Pojazd(const string& nazwa, const string& nrRejestracyjny, const Wlasciciel& wlasciciel);
	
	virtual void printInfo() const;
};

