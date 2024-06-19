#include "Column.h"

Column::Column(const std::string& aNazwa, int aRozmiar, TypWykresu aTyp)
    : Wykres(aNazwa, aRozmiar, aTyp) {
    std::cout << "Konstruktor Column\n";
}

Column::Column()
    : Column("Default Column", 0, TypWykresu::Column) {
    std::cout << "Konstruktor domyœlny Column\n";
}

Column::~Column() {
    std::cout << "Destruktor Column\n";
}

void Column::draw() {
    std::cout << "Rysowanie wykresu typu Column\n";
}
