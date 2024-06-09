//#include <"funkcje.h">
#include "ciezarowy.h"
#include "menu.h"
#include "Motocykl.h"
#include "Pojazd.h"
#include "osobowy.h"
#include "Wlasciciel.h"
#include "RejestrPojazdów.h"
#include <iostream>
#include <fstream>
#include <string>

void Wczytaj(const std::string& nazwaPliku, RejestrPojazdow& rejestr) {
	std::ifstream plik(nazwaPliku);
	if (!plik_is_open()) {
		std::cout << "Nie uda³o siê otworzyæ pliku" << std::endl;
	}
	std::string linia;
	while (std::getline(plik, linia)) {
		std::stringstream ss(linia);
		std::string typ, imie, nazwisko, pesel, nrRejestracyjny, nazwa;
		int iloscPasazerow, ladownosc, pojemnoscSilnika, mocSilnika;
		ss >> typ >> imie >> nazwisko >> pesel >> nrRejestracyjny >> nazwa;
		Wlasciciel wlasciciel(imie, nazwisko, pesel);
		if (typ == "SamochodOsobowy") {
			ss >> iloscPasazerow;
			rejestr.dodajPojazd(std::make_unique<SamochodOsobowy>(nazwa, nrRejestracyjny, wlasciciel, iloscPasazerow));
		}
		else if (typ == "SamochodCiezarowy") {
			ss >> ladownosc;
			rejestr.dodajPojazd(std::make_unique<SamochodCiezarowy>(nazwa, nrRejestracyjny, wlasciciel, ladownosc));
		}
		else if (typ=="Motocykl"){
			ss >> pojemnoscSilnika >> mocSilnika;
			rejestr.dodajPojazd(std::make_unique<Motocykl>(nazwa, nrRejestracyjny, wlasciciel, pojemnoscSilnika, mocSilnika))
		}
		}
	plik.close();
	}
}
