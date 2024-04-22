#include "OsLiczbowa.h"
#include "ZbiórOsi.h"
#include <iostream>
 void AuxFun(const OsLiczbowa& obj) {
	obj.wypisz();
}
int main() {
	std::cout << "Liczba obiektow przed utworzeniem" << OsLiczbowa::getIlosc() << std::endl;

	OsLiczbowa* obj1 = new OsLiczbowa();
	OsLiczbowa* obj2 = new OsLiczbowa(5.3, 10.4);
	OsLiczbowa* obj3 = new OsLiczbowa(0, 100, 10);
	OsLiczbowa* obj4 = new OsLiczbowa(*obj2);
	std::cout << "Liczba obiektow po utworzeniu" << OsLiczbowa::getIlosc() << std::endl;
	AuxFun(*obj1);
	AuxFun(*obj2);
	AuxFun(*obj3);
	AuxFun(*obj4);
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	std::cout << "Liczba obiektow po usunieciu" << OsLiczbowa::getIlosc() << std::endl;
	ZbiorOsi zbior(1);
	ZbiorOsi zbior2(3);
	zbior = zbior2;
	OsLiczbowa o(1, 3);
	o *= 3; 
	std::cout << o.getMin() << " " << o.getMax() << std::endl; 
	o /= 3; 
	std::cout << o.getMin() << " " << o.getMax() << std::endl; 
	OsLiczbowa o1(1, 3);
	zbior += o1;

	return 0;
}