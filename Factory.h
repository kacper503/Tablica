#pragma once // Uruchomienie tylko raz
#include "Lista.h" // Dołaczenie nagłowka Lista.h


// Klasa Factory
class Factory {
public:
    static ListaDwukierunkowa* utworzListe() {
        return new ListaDwukierunkowa();
    }
};