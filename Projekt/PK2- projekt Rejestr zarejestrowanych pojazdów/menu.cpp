#include "menu.h"
#include <iostream>

void wyswietlMenu() {
	std::cout << "Menu:" << std::endl;
	std::cout << "1.Dodaj nowego w³aœciciela" << std::endl;
	std::cout << "2. Dodaj nowy pojazd:" << std::endl;
	std::cout << "3. Usun pojazd:" << std::endl;
	std::cout << "4. Zmien wlasciciela pojazdu" << std::endl;
	std::cout << "5. Wypisz wszystkie pojazdy" << std::endl;
	std::cout << "6. Zapisz rejestr do pliku" << std::endl;
	std::cout << "7. Wczytaj rejestr z pliku" << std::endl;
	std::cout << "0. Zakoncz program" << std::endl;
}
void menu() {
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
	switch(wybor){
	case 1: {
		break;
	}
	case 2: {
		break;
	}
	case 3: {
		break;
	}case 4: {
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
	default: {
		std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
		break;
	}
}