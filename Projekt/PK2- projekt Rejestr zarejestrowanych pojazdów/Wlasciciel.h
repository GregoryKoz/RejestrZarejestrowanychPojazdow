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
	Wlasciciel(const string& im, const string& naz, const string& pes);
	string getImie() const;
	string getNazwisko() const;
	string getPesel() const;
	
	
};

