#include "Series.h"

Series::Series(int aLiczbaPunktow, const std::string& aNazwa)
    : Name(aNazwa), liczbaPunktow(aLiczbaPunktow) {
    data = new double[liczbaPunktow];
    std::cout << "Konstruktor Series\n";
}

Series::Series()
    : Series(0, "Default Series") {
    std::cout << "Konstruktor domyœlny Series\n";
}

Series::~Series() {
    delete[] data;
    std::cout << "Destruktor Series\n";
}

std::ostream& operator<<(std::ostream& os, const Series& series) {
    os << "Liczba Punktow: " << series.liczbaPunktow << ", Nazwa: " << series.objectName;
    return os;
}
