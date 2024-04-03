

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Jako argumentu uzyj nazwy pliku z koncowka .txt" << std::endl;
        return 0;
    }

    nazwapliku = argv[1];

    if (!Wczytaj(nazwapliku) { //wczytywanie z pliku do klas
        return 0;
    }
    else
    {   wyswietlmenu(); // funkcja wypisujaca na ekran menu
        menu(); // funkcja menu pozwalaj¹ca wywo³ywaæ inne funkcje

        return 0;
    }
}