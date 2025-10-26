/**
 * @file Iterator.h
 * @brief Definicja klasy Iterator dla ListaDwukierunkowa.
 */

#pragma once // Uruchomienie tylko raz
#include "Lista.h" // Dołaczenie nagłowka Lista.h


/**
 * @class Iterator
 * @brief Klasa implementująca iterator dla ListaDwukierunkowa. 
 * Pozwala na sekwencyjny dostęp do elementów i nawigację w przód/w tył.
 */
class Iterator {
private:
    ListaDwukierunkowa::Wezel* aktualny; ///< Wskaźnik na aktualnie wskazywany węzeł.

public:
    /**
     * @brief Konstruktor iteratora.
     * @param wezel Wskaźnik na węzeł, na który ma wskazywać iterator.
     */
    Iterator(ListaDwukierunkowa::Wezel* wezel) : aktualny(wezel) {}
    
    /**
     * @brief Sprawdza, czy iterator wskazuje na ważny element.
     * @return true, jeśli aktualny węzeł nie jest nullptr; false w przeciwnym razie.
     */
    bool czyJestNastepny() const { return aktualny != nullptr; }
    
    /**
     * @brief Pobiera dane z aktualnie wskazywanego węzła.
     * Wymaga, aby iterator wskazywał na ważny element.
     * @return Wartość typu int przechowywana w węźle.
     */
    int pobierzDane() const { return aktualny->dane; }
    
    /**
     * @brief Przesuwa iterator do następnego elementu listy.
     */
    void nastepny() { if (aktualny) aktualny = aktualny->nastepny; }
    
    /**
     * @brief Przesuwa iterator do poprzedniego elementu listy.
     */
    void poprzedni() { if (aktualny) aktualny = aktualny->poprzedni; }
};