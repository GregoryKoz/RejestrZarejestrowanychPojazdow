#include "funkcje.h"
#include "ciezarowy.h"
#include "Motocykl.h"
#include "Pojazd.h"
#include "osobowy.h"
#include "Wlasciciel.h"
#include "RejestrPojazdów.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool Wczytaj(const std::string& nazwaPliku, RejestrPojazdow& rejestr) {
	std::ifstream plik(nazwaPliku);
	if (plik.is_open()) {

		std::string linia;
		while (std::getline(plik, linia)) {
			std::stringstream ss(linia);
			std::string typ, imie, nazwisko, pesel, nrRejestracyjny, nazwa, marka;
			int iloscPasazerow, ladownosc, pojemnoscSilnika, mocSilnika;
			ss >> typ >> imie >> nazwisko >> pesel >> nrRejestracyjny >> marka >> nazwa;
			Wlasciciel wlasciciel(imie, nazwisko, pesel);
			if (typ == "SamochodOsobowy") {
				ss >> iloscPasazerow;
				rejestr.dodajPojazd(std::make_unique<SamochodOsobowy>(marka,nazwa, nrRejestracyjny, wlasciciel, iloscPasazerow));
			}
			else if (typ == "SamochodCiezarowy") {
				ss >> ladownosc;
				rejestr.dodajPojazd(std::make_unique<SamochodCiezarowy>(marka,nazwa, nrRejestracyjny, wlasciciel, ladownosc));
			}
			else if (typ == "Motocykl") {
				ss >> pojemnoscSilnika >> mocSilnika;
				rejestr.dodajPojazd(std::make_unique<Motocykl>(marka,nazwa, nrRejestracyjny, wlasciciel, pojemnoscSilnika, mocSilnika));
			}
		}
		plik.close();
		std::cout << "Wczytano pomyslnie" << std::endl;
		return true;
	}
	else {
		std::cout << "Nie mozna wczytac pliku" << std::endl;
		return false;
	}
}

void wyswietlMenu() {
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Dodaj nowy pojazd:" << std::endl;
	std::cout << "2. Usun pojazd" << std::endl;
	std::cout << "3. Zmien wlasciciela pojazdu" << std::endl;
	std::cout << "4. Wypisz wszystkie pojazdy" << std::endl;
	std::cout << "5. Zapisz rejestr do pliku" << std::endl;
	std::cout << "6. Wczytaj rejestr z pliku" << std::endl;
	std::cout << "0. Zakoncz program" << std::endl;
}
void menu(RejestrPojazdow& rejestr) {
	int wybor = -1;
	while (wybor != 0) {
		std::cout << "Wybierz opcje: ";
		std::cin >> wybor;

		while (!std::cin) {
			std::cout << "Bledne dane wejsciowe. Wprowadzono niepoprawny znak." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Wybierz opcje: ";
			std::cin >> wybor;
		}
		switch (wybor) {
		case 1: {
			string marka, nazwa, nrRejestracyjny;
			std::cout << "Podaj marke: " << std::endl;
			std::cin >> marka;
			std::cout << "Podaj nazwe: ";
			std::cin >> nazwa;
			std::cout << "Podaj numer rejestracyjny: ";
			std::cin >> nrRejestracyjny;
			// Pamietaj: musze zrobic coœ o w³ascicielu
			std::cout << "Jakiego typu pojazd chcesz dodac: " << std::endl;
			std::cout << "1. Samochod osobowy" << std::endl;
			std::cout << "2. Motocykl" << std::endl;
			std::cout << "3. Samochod ciezarowy" << std::endl;
			int typpojazdu = -1;
			std::cin >> typpojazdu;
			if (typpojazdu == 1) {
				int liczbaPasazerow;
				std::cout << "Podaj liczbe miejsc dla pasa¿erow: ";
				std::cin >> liczbaPasazerow;

			}
			else if (typpojazdu == 2) {
				int pojemnoscSilnika, mocSilnika;
				std::cout << "Podaj pojemnosc silnika: " << std::endl;
				std::cin >> pojemnoscSilnika;
				std::cout << "Podaj moc silnika: " << std::endl;
				std::cin >> mocSilnika;
			}
			else if(typpojazdu == 3){}
			else {
				std::cout << "Nieznany typ pojazdu" << std::endl;
			}
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}case 4: {
			rejestr.wyswietlPojazdy();
			break;
		}case 5: {
			break;
		}case 6: {
			break;
		}case 7: {
			break;
		}case 8: {
			break;
		}
		case 0: {
			std::cout << "Koniec programu." << std::endl;
			break;
		}
		default: {
			std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
			break;
		}
		}
	}
}
	





