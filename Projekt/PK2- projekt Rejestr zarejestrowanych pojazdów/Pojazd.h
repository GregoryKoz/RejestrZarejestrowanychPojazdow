#pragma once
#include <string>
#include "Wlasciciel.h"
using namespace std;
class Pojazd
{
protected:
	string nazwa;
	string typ;
	string nrRejestracyjny;
	Wlasciciel wlasciciel;
public:
	Pojazd(const string& nazwa,const string& typ, const string& nr, const Wlasciciel& wl);
	string getNazwa() const;
	string getTyp() const;
	string getNr() const;
	Wlasciciel getWl() const;

};

