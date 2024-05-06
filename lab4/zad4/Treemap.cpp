#include "Treemap.h"

Treemap::Treemap(const std::string& nazwa, int rozmiar) : Wykres(10, nazwa, TypWykresu::Treemap) {}
Treemap::~Treemap() {}
void Treemap::draw() const {
	std::cout << "Rysowanie treemap: " << nazwa << std::endl;
}
