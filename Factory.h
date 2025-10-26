/**
 * @file Factory.h
 * @brief Definicja klasy Factory służącej do tworzenia instancji ListaDwukierunkowa.
 */

#pragma once // Uruchomienie tylko raz
#include "Lista.h" // Dołaczenie nagłowka Lista.h


/**
 * @class Factory
 * @brief Statyczna klasa fabrykująca do tworzenia obiektów ListaDwukierunkowa.
 */
class Factory {
public:
    /**
     * @brief Statyczna metoda tworząca nową instancję ListaDwukierunkowa.
     * @return Wskaźnik na nowo utworzony obiekt ListaDwukierunkowa.
     */
    static ListaDwukierunkowa* utworzListe() {
        return new ListaDwukierunkowa();
    }
};