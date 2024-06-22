#pragma once
#include <string>
#include <iostream>
#include "Wlasciciel.h"
using namespace std;

/**
 * @brief Klasa reprezentuj¹ca pojazd.
 */
class Pojazd
{
protected:
    std::string typ;                ///< Typ pojazdu (SamochodOsobowy, motocykl, SamochodCiezarowy).
    std::string marka;              ///< Marka pojazdu.
    std::string nazwa;              ///< Nazwa pojazdu.
    std::string nrRejestracyjny;    ///< Numer rejestracyjny pojazdu.
    Wlasciciel wlasciciel;          ///< W³aœciciel pojazdu.

public:
    /**
     * @brief Konstruktor klasy Pojazd.
     * @param typ Typ pojazdu.
     * @param marka Marka pojazdu.
     * @param nazwa Nazwa pojazdu.
     * @param nrRejestracyjny Numer rejestracyjny pojazdu.
     * @param wlasciciel W³aœciciel pojazdu.
     */
    Pojazd(const std::string& typ, const std::string& marka, const std::string& nazwa, const std::string& nrRejestracyjny, const Wlasciciel& wlasciciel);

    /**
     * @brief Wyœwietla informacje o pojeŸdzie.
     */
    virtual void printInfo() const;

    /**
     * @brief Zwraca typ pojazdu.
     * @return Typ pojazdu.
     */
    virtual string getTyp() const;

    /**
     * @brief Zwraca markê pojazdu.
     * @return Marka pojazdu.
     */
    virtual string getMarka() const;

    /**
     * @brief Zwraca nazwê pojazdu.
     * @return Nazwa pojazdu.
     */
    virtual string getNazwa() const;

    /**
     * @brief Zwraca numer rejestracyjny pojazdu.
     * @return Numer rejestracyjny pojazdu.
     */
    virtual string getnrRejestracyjny() const;

    /**
     * @brief Ustawia nowego w³aœciciela pojazdu.
     * @param nowyWlasciciel Nowy w³aœciciel pojazdu.
     */
    void ustawWlasciciela(const Wlasciciel& nowyWlasciciel);

    /**
     * @brief Zwraca w³aœciciela pojazdu.
     * @return Referencja do w³aœciciela pojazdu.
     */
    const Wlasciciel& getWlasciciel() const;
};
