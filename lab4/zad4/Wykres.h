#pragma once
#include "ZbiórOsi.h"
class Wykres : public ZbiorOsi
{
public:
	string nazwa;
	enum TypWykresu { XY, Column, Sunburst, Treemap } typ;
	Wykres(int rozmiar, string nazwa, TypWykresu typ);
	Wykres();
	~Wykres();
	Wykres(const Wykres& wykres);
	friend std::ostream& operator<<(std::ostream& os, const Wykres& wykres);
	Wykres(Wykres&& wykres) noexcept;
	Wykres& operator=(const Wykres& wykres);
	Wykres& operator=(Wykres&& wykres) noexcept;
	void virtual draw();
};

