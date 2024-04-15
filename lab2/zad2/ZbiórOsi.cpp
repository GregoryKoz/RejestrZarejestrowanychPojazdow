#include "ZbiórOsi.h"

ZbiorOsi::ZbiorOsi(int rozmiar) {
	if (rozmiar >= 1) {
		osie = new OsLiczbowa[rozmiar];
	}
	else {
		osie = nullptr;
	}
}
ZbiorOsi::ZbiorOsi(const ZbiorOsi& zbior) {
	rozmiar = zbior.rozmiar;
		osie = new OsLiczbowa[rozmiar];
	for (int i = 0; i < rozmiar; ++i) {
		osie[i] = zbior.osie[i];
	}
}
ZbiorOsi::~ZbiorOsi() {
	if (osie != nullptr) {
		delete[] osie;
	}
}
ZbiorOsi::ZbiorOsi(ZbiorOsi&& zbior) {
	osie = zbior.osie;
		rozmiar = zbior.rozmiar;

}
std::ostream& operator<<(std::ostream& s, const ZbiorOsi& zbior){
	for (int i = 0; i < zbior.rozmiar; ++i) {
		s << "Oœ " << i << ": " << zbior.osie[i] << std::endl;
	}
	return s;
}
ZbiorOsi& ZbiorOsi::operator=(const ZbiorOsi& zbior) {
	if (this != &zbior) {
		delete[] osie;
		rozmiar = zbior.rozmiar;
		osie = new OsLiczbowa[rozmiar];
		for (int i = 0; i < rozmiar; ++i) {
			osie[i] = zbior.osie[i];
		}
		return *this;
	}
}
	ZbiorOsi& ZbiorOsi::operator=(ZbiorOsi && zbior) {
		if (this != &zbior) {
			delete[]osie;
			osie = zbior.osie;
			rozmiar = zbior.rozmiar;
			zbior.osie = nullptr;
			zbior.rozmiar = 0;
			}
		return *this;
	}
