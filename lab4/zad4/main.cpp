#include "OsLiczbowa.h"
#include "ZbiórOsi.h"
#include "Wykres.h"
#include "Column.h"
#include "Treemap.h"
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
void auxFun_4_3() {
	Wykres* wykresy[3];
	wykresy[0] = new Wykres(10,"Wykres", Wykres::TypWykresu::XY);
	wykresy[1] = new Column("Kolumna");
	wykresy[2] = new Treemap("Treemap");
	for (int i = 0; i < 3; ++i) {
		wykresy[i]->draw();
	}
	delete wykresy[0];
	delete wykresy[1];
	delete wykresy[2];
}
void auxFun_4_4(Wykres* wykres) {
	if (dynamic_cast<Wykres*>(wykres)) {
		std::cout << "poprawnie" << std::endl;
	}
	else {
		std::cout << "nullptr" << std::endl;
	}
	
}
int main() {
	//aux_3();
	Wykres wykres(10, "Wykres_1", Wykres::TypWykresu::XY);
	wykres.draw();
	auxFun_4_3();
	auxFun_4_4(&wykres);
	return 0;
}