#include "Pojazd.h"
#include "Wlasciciel.h"

using namespace std;

Pojazd::Pojazd(const std::string& typ, const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel)
	: typ(typ), marka(marka), nazwa(nazwa), nrRejestracyjny(nrRejestracyjny), wlasciciel(wlasciciel) {}


void Pojazd::printInfo() const {
	cout << "Typ: " << typ << endl;
	cout << "Marka: " << marka << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Numer rejestracjny: " << nrRejestracyjny << endl;
	cout << "Wlasciciel: ";  
	wlasciciel.printInfo();

}
string Pojazd::getMarka() const {
	return marka;
}
string Pojazd::getNazwa() const {
	return nazwa;
}
string Pojazd::getnrRejestracyjny() const {
	return nrRejestracyjny;
}
string Pojazd::getTyp() const {
	return typ;
}
void Pojazd::ustawWlasciciela(const Wlasciciel& nowyWlasciciel) {
	wlasciciel = nowyWlasciciel;
}
const Wlasciciel& Pojazd::getWlasciciel() const {
	return wlasciciel;
}

void Pojazd::zapiszDoPliku(std::ofstream& plik) const {
	plik << "Typ: " << typ << std::endl;
	plik << "Marka: " << marka << std::endl;
	plik << "Nazwa: " << nazwa << std::endl;
	plik << "Numer rejestracyjny: " << nrRejestracyjny << std::endl;
	plik << "Wlasciciel: " << wlasciciel.getImie() << " " << wlasciciel.getNazwisko() << " " << wlasciciel.getPesel() << std::endl;
}

void Pojazd::zapiszKoniec(std::ofstream& plik) const
{
	plik << typ << " " << wlasciciel.getImie() << " " << wlasciciel.getNazwisko() << " " << wlasciciel.getPesel() << " " <<
		nrRejestracyjny << " " << marka <<" "<< nazwa <<" ";
}



