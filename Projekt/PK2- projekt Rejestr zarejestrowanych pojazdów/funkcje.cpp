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
			Wlasciciel* istniejacyWlasciciel = rejestr.znajdzWlasciciela(pesel);
			if (!istniejacyWlasciciel) {
				rejestr.dodajWlasciciela(wlasciciel);
				istniejacyWlasciciel = rejestr.znajdzWlasciciela(pesel);
			}
			if (typ == "SamochodOsobowy") {
				ss >> iloscPasazerow;
				rejestr.dodajPojazd(new SamochodOsobowy(marka, nazwa, nrRejestracyjny, wlasciciel, iloscPasazerow));
			}
			else if (typ == "SamochodCiezarowy") {
				ss >> ladownosc;
				rejestr.dodajPojazd(new SamochodCiezarowy(marka, nazwa, nrRejestracyjny, wlasciciel, ladownosc));
			}
			else if (typ == "Motocykl") {
				ss >> pojemnoscSilnika >> mocSilnika;
				rejestr.dodajPojazd(new Motocykl(marka, nazwa, nrRejestracyjny, wlasciciel, pojemnoscSilnika, mocSilnika));
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
bool Zapisz(const std::string& nazwaPliku, const RejestrPojazdow& rejestr) {
	std::ofstream plik(nazwaPliku);
	if (plik.is_open()) {
		for (const auto& pojazd : rejestr.getPojazdy()) {
			plik << pojazd->getTyp() << " "
				<< pojazd->getWlasciciel().getImie() << " "
				<< pojazd->getWlasciciel().getNazwisko() << " "
				<< pojazd->getWlasciciel().getPesel() << " "
				<< pojazd->getnrRejestracyjny() << " "
				<< pojazd->getMarka() << " "
				<< pojazd->getNazwa() << " ";
			if (SamochodOsobowy* so = dynamic_cast<SamochodOsobowy*>(pojazd)) {
				plik << so->getIloscPasazerow();
			}
			else if (SamochodCiezarowy* sc = dynamic_cast<SamochodCiezarowy*>(pojazd)) {
				plik << sc->getLadownosc();
			}
			else if (Motocykl* m = dynamic_cast<Motocykl*>(pojazd)) {
				plik << m->getPojemnoscSilnika() << " " << m->getMocSilnika();
			}
			plik << std::endl;
		}
		plik.close();
		return true;
	}
	else {
		std::cout << "Nie mozna zapisac pliku" << std::endl;
		return false;
	}
}

void wyswietlMenu() {
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Dodaj nowy pojazd" << std::endl;
	std::cout << "2. Usun pojazd" << std::endl;
	std::cout << "3. Zmien wlasciciela pojazdu" << std::endl;
	std::cout << "4. Wypisz wszystkie pojazdy" << std::endl;
	std::cout << "5. Zapisz typ pojazdu do pliku" << std::endl;
	std::cout << "6. Wypisz wszystkich wlascicieli" << std::endl;
	std::cout << "7. Zapisz pojazdy wybranego wlasciciela do pliku " << std::endl;
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
			string marka, nazwa, nrRejestracyjny, pesel;
			std::cout << "Podaj marke (1 wyraz- wiecej nie jest brane pod uwage): ";
			std::cin >> marka;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Podaj nazwe (1 wyraz- wiecej nie jest brane pod uwage): ";
			std::cin >> nazwa;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			bool poprawnyNr = false;
			while (!poprawnyNr) {
				cout << "Podaj numer rejestracyjny: ";
				cin >> nrRejestracyjny;
				poprawnyNr = true;
				for (auto pojazd : rejestr.getPojazdy()) {
					if (pojazd->getnrRejestracyjny() == nrRejestracyjny) {
						poprawnyNr = false;
						std::cout << "Pojazd o takim numerze juz istnieje. Sprobuj ponownie." << std::endl;
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						break;
					}
				}
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Lista wlascicieli w systemie: " << std::endl;
			rejestr.wypiszWlascicieli();
			bool poprawnyPesel = false;
			while (!poprawnyPesel) {
				std::cout << "Podaj pesel wlasciciela pojazdu (11cyfr): ";
				std::cin >> pesel;
				if (pesel.size() == 11) {
					poprawnyPesel = true;
					for (char c : pesel) {
						if (!isdigit(c)) {
							poprawnyPesel = false;
							break;
						}
					}
				}
				if (!poprawnyPesel) {
					std::cout << "Podano bledny pesel. Sprobuj ponownie." << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
			}
			Wlasciciel* wlasciciel = nullptr;
			if (rejestr.znajdzWlasciciela(pesel) == nullptr) {
				string imie, nazwisko;
				std::cout << "Nie znaleziono wlasciciela o takim peselu w systemie - tworzymy nowego." << std::endl;
				bool poprawneImie = false;
				while (!poprawneImie) {
					std::cout << "Podaj imie: ";
					std::cin >> imie;
					poprawneImie = true;
					for (char c : imie) {
						if (!isalpha(c)) {
							poprawneImie = false;
							std::cout << "Imie nie moze zawierac cyfr. Sprobuj ponownie." << std::endl;
							break;
						}
					}
				}
				bool poprawneNazwisko = false;
				while (!poprawneNazwisko) {
					std::cout << "Podaj nazwisko: ";
					std::cin >> nazwisko;
					poprawneNazwisko = true;
					for (char c : nazwisko) {
						if (!isalpha(c)) {
							poprawneNazwisko = false;
							std::cout << "Nazwisko nie moze zawierac cyfr. Sprobuj ponownie." << std::endl;
							break;
						}
					}
				}
				wlasciciel = new Wlasciciel(imie, nazwisko, pesel);
				rejestr.dodajWlasciciela(*wlasciciel);

			}
			else {
				wlasciciel = rejestr.znajdzWlasciciela(pesel);
			}
			std::cout << "Jakiego typu pojazd chcesz dodac: " << std::endl;
			std::cout << "1. Samochod osobowy" << std::endl;
			std::cout << "2. Motocykl" << std::endl;
			std::cout << "3. Samochod ciezarowy" << std::endl;
			int typpojazdu=-1;
			std::cin >> typpojazdu;
			while (!std::cin || typpojazdu < 1 || typpojazdu > 3) {
				std::cout << "Nieznany typ pojazdu. Sprobuj ponownie." << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Jakiego typu pojazd chcesz dodac: " << std::endl;
				std::cout << "1. Samochod osobowy" << std::endl;
				std::cout << "2. Motocykl" << std::endl;
				std::cout << "3. Samochod ciezarowy" << std::endl;
				std::cin >> typpojazdu;
			}
			if (typpojazdu == 1) {
				int liczbaPasazerow;
				std::cout << "Podaj liczbe miejsc dla pasazerow (max 9): ";
				std::cin >> liczbaPasazerow;
				while (!std::cin || liczbaPasazerow<1 || liczbaPasazerow >9) {
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj ponownie" << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Podaj liczbe miejsc dla pasazerow (max 9): ";
					std::cin >> liczbaPasazerow;
				}
				rejestr.dodajPojazd(new SamochodOsobowy(marka, nazwa, nrRejestracyjny, *wlasciciel, liczbaPasazerow));
				std::cout << "Dodano pojazd" << std::endl;
			}
			else if (typpojazdu == 2) {
				int pojemnoscSilnika, mocSilnika;
				std::cout << "Podaj pojemnosc silnika: ";
				std::cin >> pojemnoscSilnika;
				while (!std::cin || pojemnoscSilnika <= 0) {
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj ponownie" << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Podaj pojemnosc silnika: ";
					std::cin >> pojemnoscSilnika;
				}
				std::cout << "Podaj moc silnika: ";
				std::cin >> mocSilnika;
				while (!std::cin || mocSilnika <= 0) {
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj ponownie" << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Podaj moc silnika: ";
					std::cin >> mocSilnika;
				}
				rejestr.dodajPojazd(new Motocykl(marka, nazwa, nrRejestracyjny, *wlasciciel, pojemnoscSilnika, mocSilnika));
				std::cout << "Dodano pojazd" << std::endl;
			}
			else if (typpojazdu == 3) {
				int ladownosc;
				std::cout << "Podaj ladownosc: ";
				std::cin >> ladownosc;
				while (!std::cin || ladownosc <= 0) {
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj ponownie" << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Podaj ladownosc: ";
					std::cin >> ladownosc;
				}
				rejestr.dodajPojazd(new SamochodCiezarowy(marka, nazwa, nrRejestracyjny, *wlasciciel, ladownosc));
				std::cout << "Dodano pojazd" << std::endl;
			}
			break;
		}
		case 2: {
			string nrRejestracyjny;
			std::cout << "Podaj numer rejestracyjny pojazdu do usuniecia: ";
			std::cin >> nrRejestracyjny;
			rejestr.usunPojazd(nrRejestracyjny);
			break;
		}
		case 3: {
			string nrRejestracyjny, pesel, imie, nazwisko;
			std::cout << "Podaj numer rejestracyjny pojazdu do zmiany wlasciciela: ";
			std::cin >> nrRejestracyjny;
			std::cout << "Wlasciciele zapisani w systemie:" << std::endl;
			rejestr.wypiszWlascicieli();
			bool poprawnyPesel = false;
			while (!poprawnyPesel) {
				std::cout << "Podaj pesel wlasciciela pojazdu (11cyfr): ";
				std::cin >> pesel;
				if (pesel.size() == 11) {
					poprawnyPesel = true;
					for (char c : pesel) {
						if (!isdigit(c)) {
							poprawnyPesel = false;
							break;
						}
					}
				}
				if (!poprawnyPesel) {
					std::cout << "Podano bledny pesel. Sprobuj ponownie." << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
			}
			Wlasciciel* nowyWlasciciel = rejestr.znajdzWlasciciela(pesel);
			if (!nowyWlasciciel) {
				std::cout << "Nieznaleziono wlasciciela o podanym numerze pesel- tworzymy nowego.";
				bool poprawneImie = false;
				while (!poprawneImie) {
					std::cout << "Podaj imie: ";
					std::cin >> imie;
					poprawneImie = true;
					for (char c : imie) {
						if (!isalpha(c)) {
							poprawneImie = false;
							std::cout << "Imie nie moze zawierac cyfr. Sprobuj ponownie." << std::endl;
							break;
						}
					}
				}
				bool poprawneNazwisko = false;
				while (!poprawneNazwisko) {
					std::cout << "Podaj nazwisko: ";
					std::cin >> nazwisko;
					poprawneNazwisko = true;
					for (char c : nazwisko) {
						if (!isalpha(c)) {
							poprawneNazwisko = false;
							std::cout << "Nazwisko nie moze zawierac cyfr. Sprobuj ponownie." << std::endl;
							break;
						}
					}
				}
				nowyWlasciciel = new Wlasciciel(imie, nazwisko, pesel);
				rejestr.dodajWlasciciela(*nowyWlasciciel);
			}
			rejestr.zmienWlasciciela(nrRejestracyjny, *nowyWlasciciel);
			break;
		}case 4: {
			rejestr.wyswietlPojazdy();
			break;
		}case 5: {
			string typ, nazwaPliku;
			std::cout << "Podaj typ pojazdu: " << std::endl;
			std::cout << "1. Samochod osobowy" << std::endl;
			std::cout << "2. Motocykl" << std::endl;
			std::cout << "3. Samochod ciezarowy" << std::endl;
			int typpojazdu = -1;
			std::cin >> typpojazdu;
			while (!std::cin || typpojazdu < 1 || typpojazdu > 3) {
				std::cout << "Nieznany typ pojazdu. Sprobuj ponownie." << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Jakiego typu pojazd chcesz dodac: " << std::endl;
				std::cout << "1. Samochod osobowy" << std::endl;
				std::cout << "2. Motocykl" << std::endl;
				std::cout << "3. Samochod ciezarowy" << std::endl;
				std::cin >> typpojazdu;
			}
			if (typpojazdu == 1) {
				typ = "SamochodOsobowy";
				nazwaPliku = "SamochodOsobowy.txt";
			}
			else if (typpojazdu == 2) {
				typ = "Motocykl";
				nazwaPliku = "Motocykl.txt";
			}
			else if (typpojazdu == 3) {
				typ = "SamochodCiezarowy";
				nazwaPliku = "SamochodCiezarowy.txt";
			}
			

			rejestr.zapiszPojazdyTypu(typ, nazwaPliku);
			std::cout << "Zapisano do pliku: " << nazwaPliku << std::endl;
			break;
		}case 6: {
			rejestr.wypiszWlascicieli();
			break;
		}case 7: {
			string pesel, nazwaPliku;
			rejestr.wypiszWlascicieli();
			std::cout << "Podaj pesel wlasciciela, ktorego pojazdy chcesz zapisac: ";
			std::cin >> pesel;
			Wlasciciel* wlasciciel = rejestr.znajdzWlasciciela(pesel);
			if (wlasciciel) {
				nazwaPliku = wlasciciel->getImie() + "_" + wlasciciel->getNazwisko() + "_pojazdy.txt";
				rejestr.zapiszPojazdyWlasciciela(pesel, nazwaPliku);
			}
			else {
				std::cout << "Wlasciciel o podanym numerze PESEL nie istnieje." << std::endl;
			}
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
	





