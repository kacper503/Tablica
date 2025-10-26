#pragma once // Uruchomienie tylko raz
#include <iostream>
using namespace std;

class Iterator; // deklaracja

// Lista Dwukierunkowa
class ListaDwukierunkowa {
public:
    struct Wezel {
        int dane;
        Wezel* poprzedni;
        Wezel* nastepny;
        Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
        
    };
    ListaDwukierunkowa();
    ~ListaDwukierunkowa(); // destruktor

    void dodajNaKoniec(int wartosc); // Dodawanie na koniec
    void dodajNaPoczatek(int wartosc); // Dodawanie na początek
    void dodajIndex(int indeks, int wartosc); // Dodawanie na miejsce indeksu

    void usunZKonca(); // Usuwanie z końca
    void usunZPoczatku(); // Usuwanie z początku
    void usunZIndex(int indeks); // Usuwanie z miejsca indeksu

    Iterator poczatek();

    friend class Iterator; // deklaracja przyjaźni

private:
    Wezel* pierwszy;
    Wezel* ostatni;
};