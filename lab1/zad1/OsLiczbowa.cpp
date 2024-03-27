#include <iostream>

class OsLiczbowa
{
public:
	double min, max, interval;

	OsLiczbowa() {
		min = 0;
		max = 10;
		interval = 1;
		std::cout << "OsLiczbowa- Konstruktor bezargumentowy" << std::endl;

	}
	OsLiczbowa(double min_war, double max_war) {
		min = min_war;
		max = max_war;
		interval = (max_war - min_war) / 10;
		std::cout << "OsLiczbowa- Konstruktor dwuargumentowy" << std::endl;
	}
	OsLiczbowa(const OsLiczbowa& os) {
		min = os.min;
		max = os.max;
		interval = os.interval;
		std::cout << "OsLiczbowa- Konstruktor kopiuj¹cy" << std::endl;
	}
	~OsLiczbowa() {
		std::cout << "OsLiczbowa- destruktor" << std::endl;
	}
};

