/**
 * @file Lista.h
 * @brief Definicja klasy ListaDwukierunkowa i jej struktury Wezel.
 */

#pragma once // Uruchomienie tylko raz
#include <iostream>
using namespace std;

class Iterator; // deklaracja

/**
 * @class ListaDwukierunkowa
 * @brief Implementacja dwukierunkowej listy powiązanej.
 */
class ListaDwukierunkowa {
public:
    /**
     * @struct Wezel
     * @brief Struktura reprezentująca pojedynczy węzeł listy dwukierunkowej.
     */
    struct Wezel {
        int dane;           ///< Dane przechowywane w węźle.
        Wezel* poprzedni;   ///< Wskaźnik na poprzedni węzeł.
        Wezel* nastepny;    ///< Wskaźnik na następny węzeł.
        
        /**
         * @brief Konstruktor węzła.
         * @param wartosc Wartość, która ma być przechowywana w węźle.
         */
        Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
        
    };
    
    /**
     * @brief Konstruktor domyślny klasy ListaDwukierunkowa.
     */
    ListaDwukierunkowa();
    
    /**
     * @brief Destruktor klasy ListaDwukierunkowa. 
     * Zwolnienie pamięci zajmowanej przez wszystkie węzły.
     */
    ~ListaDwukierunkowa(); 

    /**
     * @brief Dodaje nowy element na koniec listy.
     * @param wartosc Wartość do dodania.
     */
    void dodajNaKoniec(int wartosc); 
    
    /**
     * @brief Dodaje nowy element na początek listy.
     * @param wartosc Wartość do dodania.
     */
    void dodajNaPoczatek(int wartosc); 
    
    /**
     * @brief Dodaje nowy element pod określonym indeksem.
     * Jeśli indeks jest za duży, element jest dodawany na koniec.
     * @param indeks Miejsce, w którym ma zostać wstawiony element (0-indeksowany).
     * @param wartosc Wartość do dodania.
     */
    void dodajIndex(int indeks, int wartosc); 

    /**
     * @brief Usuwa element z końca listy.
     */
    void usunZKonca(); 
    
    /**
     * @brief Usuwa element z początku listy.
     */
    void usunZPoczatku(); 
    
    /**
     * @brief Usuwa element pod określonym indeksem.
     * @param indeks Indeks elementu do usunięcia (0-indeksowany).
     */
    void usunZIndex(int indeks); 

    /**
     * @brief Zwraca iterator wskazujący na pierwszy element listy.
     * @return Obiekt Iterator ustawiony na 'pierwszy'.
     */
    Iterator poczatek();
    
    /**
     * @brief Zwraca iterator wskazujący na ostatni element listy.
     * @return Obiekt Iterator ustawiony na 'ostatni'.
     */
    Iterator koniec();
    
    /**
     * @brief Wyświetla wszystkie elementy listy w odwrotnej kolejności.
     */
    void wyswietlOdwr();

    /**
     * @brief Deklaracja przyjaźni z klasą Iterator.
     */
    friend class Iterator; 

private:
    Wezel* pierwszy;    ///< Wskaźnik na pierwszy węzeł listy.
    Wezel* ostatni;     ///< Wskaźnik na ostatni węzeł listy.
};