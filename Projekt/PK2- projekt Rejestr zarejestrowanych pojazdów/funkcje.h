#include <string>
#include "Pojazd.h"
#include "RejestrPojazdów.h"

bool Wczytaj(const std::string& nazwaPliku, RejestrPojazdow& rejestr);

void wyswietlMenu();
void menu(RejestrPojazdow& rejestr);
bool Zapisz(const std::string& nazwaPliku, const RejestrPojazdow& rejestr);