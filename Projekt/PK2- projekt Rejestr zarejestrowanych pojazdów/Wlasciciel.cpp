#include "Wlasciciel.h"
#include <iostream>

Wlasciciel::Wlasciciel(const string& imie, const string& nazwisko, const string& pesel) : imie(imie), nazwisko(nazwisko), pesel(pesel) {}

void Wlasciciel::printInfo() const {
    std::cout << imie << " " << nazwisko << " Pesel: " << pesel << std::endl;
}
string Wlasciciel::getPesel() const {
    return pesel;
}
string Wlasciciel::getNazwisko() const {
    return nazwisko;
}
string Wlasciciel::getImie() const {
    return imie;
}
