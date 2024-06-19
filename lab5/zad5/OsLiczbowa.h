#pragma once
#ifndef OSLICZBOWA_H
#define OSLICZBOWA_H
using namespace std;
#include <iostream>
class OsLiczbowa
{
private:
	double min;
	double max;
	double interval;
	static int ilosc;
public:
	OsLiczbowa();
	OsLiczbowa(double min_war, double max_war);
	OsLiczbowa(double min_war, double max_war, double int_war);
	OsLiczbowa(const OsLiczbowa& os);
	~OsLiczbowa();

	void setMin(double min_war);
	void setMax(double max_war);
	void setInterval(double int_war);
	double getMin() const;
	double getMax() const;
	double getInt() const;
	static int getIlosc();
	void wypisz() const;
	friend std::ostream& operator<<(std::ostream& s, const OsLiczbowa& obj);
	OsLiczbowa& operator*=(double scale);
	OsLiczbowa& operator/=(double scale);

};




#endif 


#pragma once