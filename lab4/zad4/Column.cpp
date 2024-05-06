#include "Column.h"
#include <string>;

Column::Column(const std::string& nazwa, int rozmiar): Wykres(10,nazwa,TypWykresu::Column){}
Column::~Column(){}
void Column::draw() const {
	std::cout << "Rysowanie kolumnowego wykresu: " << nazwa << std::endl;
}