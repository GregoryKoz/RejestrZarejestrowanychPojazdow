#pragma once
#include <iostream>
#include <string>
#include "Name.h"

class Series : public virtual Name {
protected:
    int liczbaPunktow;
    double* data;

public:
    Series(int aLiczbaPunktow, const std::string& aNazwa);
    Series();
    ~Series();
    friend std::ostream& operator<<(std::ostream& os, const Series& series);
};
