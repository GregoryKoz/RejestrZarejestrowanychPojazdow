#include "OsLiczbowa.h"
#include "ZbiórOsi.h"
#include "Wykres.h"
#include <iostream>
#include "Series.h"
#include "RealChart.h"
void AuxFun(const OsLiczbowa& obj) {
	obj.wypisz();

}

int main() {
  
    RealChart rc(10, "Przyklad", "series", TypWykresu::Column);
   
    std::cout << rc << std::endl;


    return 0;
}
