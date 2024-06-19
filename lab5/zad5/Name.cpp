#include "Name.h"

Name::Name(const std::string& aName)
    : objectName(aName) {
    std::cout << "Konstruktor Name\n";
}

Name::Name()
    : Name("Default Name") {
    std::cout << "Konstruktor domyœlny Name\n";
}

Name::~Name() {
    std::cout << "Destruktor Name\n";
}
