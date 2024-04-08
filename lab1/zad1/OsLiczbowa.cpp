	#include "OsLiczbowa.h"
	#include <iostream>


	OsLiczbowa::OsLiczbowa() {
		min = 0;
		max = 10;
		interval = 1;
		ilosc++;
		std::cout << "OsLiczbowa- Konstruktor bezargumentowy" << std::endl;

		}
	OsLiczbowa::OsLiczbowa(double min_war, double max_war) {
		min = min_war;
		max = max_war;
		interval = (max_war - min_war) / 10;
		ilosc++;
		std::cout << "OsLiczbowa- Konstruktor dwuargumentowy" << std::endl;
	}
	OsLiczbowa::OsLiczbowa(double min_war, double max_war, double int_war) {
		min = min_war;
		max = max_war;
		interval = int_war;
		ilosc++;
		std::cout << "OsLiczbowa- Konstruktor wieloargumentowy" << std::endl;
	}
	OsLiczbowa::OsLiczbowa(const OsLiczbowa& os) {
		min = os.min;
		max = os.max;
		interval = os.interval;
		ilosc++;
		std::cout << "OsLiczbowa- Konstruktor kopiuj¹cy" << std::endl;
		}
	OsLiczbowa::~OsLiczbowa() {
		ilosc--;
		std::cout << "OsLiczbowa- destruktor" << std::endl;
	}

	void OsLiczbowa::setMin(double min_war) {
		min = min_war;
	}
	void OsLiczbowa::setMax(double max_war) {
		max = max_war;
	}
	void OsLiczbowa::setInterval(double int_war) {
		interval = int_war;
	}
	double OsLiczbowa::getMin() const {
		return min;
	}
	double OsLiczbowa::getMax() const {
		return max;
	}
	double OsLiczbowa::getInt() const {
		return interval;
	}
	void OsLiczbowa::wypisz() const {
		std::cout << "Min: " << min << "Max: " << max << "Interval: " << interval << std::endl;
	}
	int OsLiczbowa::getIlosc() {
		return ilosc;
	}
	ostream& operator <<(ostream& s, const OsLiczbowa&obj) {
		s << "Min=" << obj.min << "Max=" << obj.max << "Interval=" << obj.interval << "\n";
		return s

	}
	
	
