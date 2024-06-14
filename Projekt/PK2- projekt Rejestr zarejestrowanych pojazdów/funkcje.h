#include <string>
#include "Pojazd.h"
#include "RejestrPojazdów.h"

bool Wczytaj(const std::string& nazwaPliku, RejestrPojazdow& rejestr);

void wyswietlMenu();
void menu(RejestrPojazdow& rejestr);