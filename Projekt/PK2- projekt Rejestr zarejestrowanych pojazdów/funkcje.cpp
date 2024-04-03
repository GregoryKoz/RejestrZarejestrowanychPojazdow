//#include <"funkcje.h">
#include <iostream>
#include <fstream>
#include <string>

void menu() {

	int wybor = -1;
	while (wybor != 0) {
		std::cout << "Wybierz opcje: " << std::endl;
		std::cin >> wybor;
		while (!std::cin) {
			std::cout << "Wprowadzono niepoprawny znak" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000. '\n');
			std::cout << "Wybierz opcje: " << std::endl;
			std::cin >> wybor;
		}
		switch (wybor) {
		case 1: {
			// zarejestruj pojazd
		}
		case 2: {
			// Dodaj w³aœciciela pojazdu
		}
		case 3: {
			//Zmien w³aœciciela pojazdu
		}
		case 4: {
			// Usuñ z bazy dany pojazd
		}
		case 5: {
			//Wydruk do pliku pojazdu danego typu
		}
		case 6: {
			//Wydruk do pliku konkretnego w³aœciciela pojazdu
		}
		case 0: {
			// KONIEC PROGRAMU
		}
		default: {
			std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
			break;
		}
		}
	}

}
