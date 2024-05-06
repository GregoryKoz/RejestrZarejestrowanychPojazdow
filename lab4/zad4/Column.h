#pragma once
#include "Wykres.h"
class Column : public Wykres
{
public:
	char* pole;
	Column(const std::string& nazwa = "", int rozmiar=10);
	~Column();
	void draw() const;
};

