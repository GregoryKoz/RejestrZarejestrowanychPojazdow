/**
 * @file RejestrPojazdow.h
 * @brief Definicja klasy RejestrPojazdow.
 */

#pragma once
#include "Pojazd.h"
#include <vector>
#include <iostream>
#include "osobowy.h"
#include "Motocykl.h"
#include "ciezarowy.h"

 /**
  * @class RejestrPojazdow
  * @brief Klasa reprezentuj¹ca rejestr pojazdów.
  */
class RejestrPojazdow {
private:
    /**
     * @brief Wektor wskaŸników na obiekty typu Pojazd.
     */
    std::vector<Pojazd*> pojazdy;

    /**
     * @brief Wektor obiektów typu Wlasciciel.
     */
    std::vector<Wlasciciel> wlasciciele;

public:
    /**
     * @brief Nazwa pliku do wczytania danych.
     */
    std::string nazwaPliku;

    /**
     * @brief Dodaje pojazd do rejestru.
     * @param pojazd WskaŸnik na obiekt typu Pojazd.
     */
    void dodajPojazd(Pojazd* pojazd);

    /**
     * @brief Usuwa pojazd z rejestru na podstawie numeru rejestracyjnego.
     * @param nrRejestracyjny Numer rejestracyjny pojazdu do usuniêcia.
     */
    void usunPojazd(const std::string& nrRejestracyjny);

    /**
     * @brief Wyœwietla wszystkie pojazdy w rejestrze.
     */
    void wyswietlPojazdy() const;

    /**
     * @brief Znajduje w³aœciciela na podstawie numeru PESEL.
     * @param pesel Numer PESEL w³aœciciela.
     * @return WskaŸnik na obiekt typu Wlasciciel, jeœli znaleziono, w przeciwnym razie nullptr.
     */
    Wlasciciel* znajdzWlasciciela(const std::string& pesel);

    /**
     * @brief Zapisuje pojazdy okreœlonego typu do pliku.
     * @param typ Typ pojazdów do zapisania.
     * @param nazwaPliku Nazwa pliku do zapisu.
     */
    void zapiszPojazdyTypu(const std::string& typ, const std::string& nazwaPliku);

    /**
     * @brief Zapisuje pojazdy nale¿¹ce do danego w³aœciciela do pliku.
     * @param pesel Numer PESEL w³aœciciela.
     * @param nazwaPliku Nazwa pliku do zapisu.
     */
    void zapiszPojazdyWlasciciela(const std::string& pesel, const std::string& nazwaPliku);

    /**
     * @brief Destruktor klasy RejestrPojazdow.
     */
    ~RejestrPojazdow();

    /**
     * @brief Wyœwietla listê w³aœcicieli.
     */
    void wypiszWlascicieli() const;

    /**
     * @brief Dodaje nowego w³aœciciela do rejestru.
     * @param wlasciciel Obiekt typu Wlasciciel do dodania.
     * @return true jeœli w³aœciciel zosta³ dodany, false jeœli ju¿ istnieje.
     */
    bool dodajWlasciciela(const Wlasciciel& wlasciciel);

    /**
     * @brief Zmienia w³aœciciela pojazdu.
     * @param nrRejestracyjny Numer rejestracyjny pojazdu.
     * @param nowyWlasciciel Nowy w³aœciciel pojazdu.
     * @return true jeœli w³aœciciel zosta³ zmieniony, false jeœli pojazd nie istnieje.
     */
    bool zmienWlasciciela(const std::string& nrRejestracyjny, const Wlasciciel& nowyWlasciciel);

    /**
     * @brief Zwraca wektor wskaŸników na obiekty typu Pojazd.
     * @return Wektor wskaŸników na obiekty typu Pojazd.
     */
    const std::vector<Pojazd*>& getPojazdy() const;
};
