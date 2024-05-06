#include "Wykres.h"
Wykres::Wykres() {
	std::cout << "Konstuktor bezargumentowy" << std::endl;
}
Wykres::Wykres(int size, string nazwa, TypWykresu typ) :ZbiorOsi(size), nazwa(nazwa), typ(typ) {

	std::cout << "Konstruktor wieloargumentowy" << std::endl;
}
Wykres::~Wykres() {
	std::cout << "Destruktor Wykres" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Wykres& wykres) {
	os << "Nazwa: " << wykres.nazwa << ", Typ: " << wykres.typ;
	return os;
}
Wykres::Wykres(const Wykres& wykres) : ZbiorOsi(wykres), nazwa(wykres.nazwa), typ(wykres.typ) {

	std::cout << "Konstuktor kopiujacy" << std::endl;
}
Wykres::Wykres(Wykres&& wykres) noexcept {
	ZbiorOsi(std::move(wykres));
	nazwa = std::move(wykres.nazwa);
	typ = std::move(wykres.typ);

}
Wykres& Wykres::operator=(const Wykres& wykres) {
	if (this != &wykres) {
		ZbiorOsi::operator=(wykres);
		nazwa = wykres.nazwa;
		typ = wykres.typ;
	}
	return *this;
}
Wykres& Wykres::operator=(Wykres&& wykres) noexcept {
	if (this != &wykres) {
		ZbiorOsi::operator=(std::move(wykres));
		nazwa = std::move(wykres.nazwa);
		typ = wykres.typ;
		std::cout << "Operator przeniesienia wykres" << std::endl;
	}
	return *this;
}
void Wykres::draw() {
	std::cout << "Nazwa wykresu: " << nazwa << std::endl;

}
