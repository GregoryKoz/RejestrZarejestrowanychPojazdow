#pragma once
#include "Wykres.h"

class Column : public Wykres {
public:
    Column(const std::string& aNazwa, int aRozmiar, TypWykresu aTyp);
    Column();
    ~Column();
    void draw() override;
};
