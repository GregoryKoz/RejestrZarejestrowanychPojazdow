#include "Wykres.h"
#include <iostream>
#include "ZbiórOsi.h"
#include "Wykres.h"

Wykres::Wykres(const std::string& aNazwa, int aRozmiar, TypWykresu aTyp)
    : Name(aNazwa), rozmiar(aRozmiar), typ(aTyp) {
    std::cout << "Konstruktor Wykres\n";
}

Wykres::Wykres()
    : Wykres("Default Wykres", 0, TypWykresu::Column) {
    std::cout << "Konstruktor domyœlny Wykres\n";
}

Wykres::~Wykres() {
    std::cout << "Destruktor Wykres\n";
}


