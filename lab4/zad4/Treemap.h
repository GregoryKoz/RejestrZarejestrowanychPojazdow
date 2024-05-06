#pragma once
#include "Wykres.h"
class Treemap : public Wykres
{
public:
	char* pole;
	Treemap(const std::string& nazwa = "Treemap", int rozmiar = 10);
	~Treemap();
	void draw() const;

};

