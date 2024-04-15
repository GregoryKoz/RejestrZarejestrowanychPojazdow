#ifndef ZBIOROSI_H
#define ZBIOROSI_H

#include "OsLiczbowa.h"

class ZbiorOsi {
public:
    OsLiczbowa* osie;
    int rozmiar;

    ZbiorOsi(int rozmiar);
    ~ZbiorOsi();
    ZbiorOsi(const ZbiorOsi& zbior);
    ZbiorOsi(ZbiorOsi&& zbior);

    friend std::ostream& operator <<(std::ostream s, const ZbiorOsi& zbior);
    ZbiorOsi& operator=(const ZbiorOsi& zbior);
    ZbiorOsi& operator=(ZbiorOsi&& zbior);

};
#endif