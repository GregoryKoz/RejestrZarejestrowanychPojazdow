#include "ciezarowy.h"
#include "Motocykl.h"
#include "Pojazd.h"
#include "osobowy.h"
#include "Wlasciciel.h"
#include "RejestrPojazdów.h"
#include "funkcje.h"




int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Jako argumentu uzyj nazwy pliku z koncowka .txt" << std::endl;
        return 0;
    }
    RejestrPojazdow rejestr;
    rejestr.nazwaPliku = argv[1];
   

    if (!Wczytaj(rejestr.nazwaPliku, rejestr)) { 
        return 0;
    }
    else
    {   wyswietlMenu(); 
        menu(rejestr);
        Zapisz(rejestr.nazwaPliku, rejestr);

        return 0;
    }
}