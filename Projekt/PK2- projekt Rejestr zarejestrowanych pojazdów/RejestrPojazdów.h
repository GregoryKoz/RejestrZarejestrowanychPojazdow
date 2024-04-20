#pragma once
#include "Pojazd.h"
#include <vector>
#include <iostream>
class RejestrPojazdów
{
private:
	vector<Pojazd*> pojazdy;
public:
	RejestrPojazdów();
	~RejestrPojazdów();
	void WczytajzPliku(const string& nazwapliku);
	void DodajPojazd(Pojazd* pojazd);
	void usunPojazd(const string& nr);
	void zmienWlasciciela(const string& nr, const Wlasciciel& nowywl);
	void ZapiszDoPliku(const string& nazwapliku);
	void NowyWlasciciel();
	

};

