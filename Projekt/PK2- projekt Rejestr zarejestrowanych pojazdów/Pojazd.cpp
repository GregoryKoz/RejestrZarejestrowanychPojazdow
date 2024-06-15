#include "Pojazd.h"
#include "Wlasciciel.h"

using namespace std;

Pojazd::Pojazd(const std::string& typ, const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel)
	: typ(typ), marka(marka), nazwa(nazwa), nrRejestracyjny(nrRejestracyjny), wlasciciel(wlasciciel) {}


void Pojazd::printInfo() const {
	cout << "Marka: " << marka << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Numer rejestracjny: " << nrRejestracyjny << endl;
	cout << "Wlasciciel: ";  
	wlasciciel.printInfo();
}


