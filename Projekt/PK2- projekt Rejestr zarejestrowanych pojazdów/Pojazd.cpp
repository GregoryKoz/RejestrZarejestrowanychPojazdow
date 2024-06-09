#include "Pojazd.h"

Pojazd::Pojazd(const string& nazwa, const string& nrRejestracyjny, const Wlasciciel& wlasciciel) : nazwa(nazwa), nrRejestracyjny(nr), Wlasciciel(wl){}

void Pojazd::printInfo() const {
	cout << "Nazwa: " << nazwa << endl;
	cout << "Numer rejestracjny" << nrRejestracyjny << endl;
	cout << "Wlasciciel: " << endl;
	wlasciciel.printInfo();
}
