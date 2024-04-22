#include "OsLiczbowa.h"
#include "ZbiórOsi.h"
#include "Wykres.h"
#include <iostream>
void AuxFun(const OsLiczbowa& obj) {
	obj.wypisz();
}
void aux_3() {
	Wykres wykres1(10, "Wykres_1", Wykres::TypWykresu::XY);
	std::cout << wykres1 << std::endl;
	Wykres wykres2;
	std::cout << wykres2 << std::endl;
	Wykres wykres3 = wykres1;
	std::cout << wykres3 << std::endl;
	Wykres wykres4 = std::move(wykres1);
	std::cout << wykres4 << std::endl;
	Wykres wykres5;
	wykres5 = wykres1;
	std::cout << wykres5 << std::endl;
	Wykres wykres6;
	wykres6 = std::move(wykres3);
	std::cout << wykres6 << std::endl;

}
int main() {
	aux_3();
	return 0;
}