#pragma once
#include "ZbiórOsi.h"
#include <string>
#include "Name.h"

enum class TypWykresu { Column, Treemap };

class Wykres : public virtual Name {
protected:
    int rozmiar;
    TypWykresu typ;

public:
    Wykres(const std::string& aNazwa, int aRozmiar, TypWykresu aTyp);
    Wykres();
    ~Wykres();
    virtual void draw() = 0;
};

