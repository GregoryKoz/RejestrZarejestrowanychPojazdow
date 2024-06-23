#pragma once
#include <string>
using namespace std;
class Wlasciciel
{
private:
	string imie;
	string nazwisko;
	string pesel;
public:
	Wlasciciel(const string& imie, const string& nazwisko, const string& pesel);
	void printInfo() const;
	string getImie() const;
	string getNazwisko() const;
	string getPesel() const;
	
	friend ostream& operator<<(ostream& os, const Wlasciciel& wlasciciel);
};

