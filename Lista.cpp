/**
 * @file Lista.cpp
 * @brief Implementacja metod klasy ListaDwukierunkowa.
 */

#include "Lista.h" // Dołaczenie nagłowka Lista.h
#include "Iterator.h" // Dołaczenie nagłowka Interator.h

/**
 * @brief Konstruktor klasy ListaDwukierunkowa.
 * Inicjuje wskaźniki pierwszy i ostatni na nullptr.
 */
ListaDwukierunkowa::ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {}


/**
 * @brief Destruktor klasy ListaDwukierunkowa.
 * Iteruje przez wszystkie węzły i zwalnia zajętą przez nie pamięć.
 */
ListaDwukierunkowa::~ListaDwukierunkowa() { 
    Wezel* aktualny = pierwszy;
    while (aktualny) {
        Wezel* nastepny = aktualny->nastepny;
        delete aktualny;
        aktualny = nastepny;
    }
}


/**
 * @brief Dodaje nowy element na koniec listy.
 * @param wartosc Wartość do dodania.
 */
void ListaDwukierunkowa::dodajNaKoniec(int wartosc) {
    Wezel* nowy = new Wezel(wartosc);
    if (!ostatni) {
        pierwszy = ostatni = nowy; // Lista pusta
    } else {
        ostatni->nastepny = nowy;
        nowy->poprzedni = ostatni;
        ostatni = nowy;
    }
}


/**
 * @brief Dodaje nowy element na początek listy.
 * @param wartosc Wartość do dodania.
 */
void ListaDwukierunkowa::dodajNaPoczatek(int wartosc) {
    Wezel* nowy = new Wezel(wartosc);
    if (!pierwszy) {
        pierwszy = ostatni = nowy; // Lista pusta
    } else {
        nowy->nastepny = pierwszy;
        pierwszy->poprzedni = nowy;
        pierwszy = nowy;
    }
}


/**
 * @brief Dodaje nowy element pod określonym indeksem.
 * Obsługuje dodanie na początek (indeks <= 0) lub na koniec (jeśli indeks za duży).
 * @param indeks Miejsce wstawienia (0-indeksowany).
 * @param wartosc Wartość do dodania.
 */
void ListaDwukierunkowa::dodajIndex(int indeks, int wartosc) {
    if (indeks <= 0) {
        dodajNaPoczatek(wartosc);
        return;
    }
    
    // Znajdź węzeł poprzedzający miejsce wstawienia
    Wezel* aktualny = pierwszy;
    for (int i = 0; i < indeks - 1 && aktualny; ++i)
        aktualny = aktualny->nastepny;

    if (!aktualny) {
        // Indeks większy niż rozmiar-1, dodaj na koniec
        dodajNaKoniec(wartosc);
        return;
    }

    Wezel* nowy = new Wezel(wartosc);
    nowy->nastepny = aktualny->nastepny;
    nowy->poprzedni = aktualny;

    if (aktualny->nastepny)
        aktualny->nastepny->poprzedni = nowy;
    else
        ostatni = nowy; // Nowy węzeł jest nowym ostatnim

    aktualny->nastepny = nowy;
}


/**
 * @brief Usuwa element z końca listy.
 */
void ListaDwukierunkowa::usunZKonca() {
    if (!ostatni) {
        return; // Lista pusta
    }
    Wezel* doUsuniecia = ostatni;
    if (pierwszy == ostatni) { // Lista ma jeden element
        pierwszy = ostatni = nullptr;
    } else {
        ostatni = ostatni->poprzedni;
        if (ostatni) {
            ostatni->nastepny = nullptr;
        } else {
            pierwszy = nullptr; // Jeśli lista była dwuelementowa, ostatni jest nullptr, ale to nie powinno się zdarzyć, gdy lista ma >1 element. Poprawka: Ostatni jest nullptr tylko gdy lista pusta - ta ścieżka dla 1 elementu.
        }
    }
    delete doUsuniecia;
}


/**
 * @brief Usuwa element z początku listy.
 */
void ListaDwukierunkowa::usunZPoczatku() {
    if (!pierwszy) {
        return; // Lista pusta
    }
    Wezel* doUsuniecia = pierwszy;
    if (pierwszy == ostatni) { // Lista ma jeden element
        pierwszy = ostatni = nullptr;
    } else {
        pierwszy = pierwszy->nastepny;
        if (pierwszy) {
            pierwszy->poprzedni = nullptr;
        } else {
            ostatni = nullptr; // Powinno być obsłużone przez sekcję z jednym elementem
        }
    }
    delete doUsuniecia;
}


/**
 * @brief Usuwa element pod określonym indeksem.
 * Obsługuje usunięcie z początku (indeks <= 0).
 * @param indeks Indeks elementu do usunięcia (0-indeksowany).
 */
void ListaDwukierunkowa::usunZIndex(int indeks) {
    if (!pierwszy) {
        return; // Lista pusta
    }

    if (indeks <= 0) {
        usunZPoczatku();
        return;
    }

    // Znajdź węzeł do usunięcia
    Wezel* aktualny = pierwszy;
    for (int i = 0; i < indeks && aktualny; ++i) {
        aktualny = aktualny->nastepny;
    }

    if (!aktualny) {
        return; // Indeks poza zakresem
    }

    // Korekta wskaźników poprzedniego węzła
    if (aktualny->poprzedni) {
        aktualny->poprzedni->nastepny = aktualny->nastepny;
    } else {
        pierwszy = aktualny->nastepny; // Element do usunięcia to 'pierwszy'
    }

    // Korekta wskaźników następnego węzła
    if (aktualny->nastepny) {
        aktualny->nastepny->poprzedni = aktualny->poprzedni;
    } else {
        ostatni = aktualny->poprzedni; // Element do usunięcia to 'ostatni'
    }

    delete aktualny;
}


/**
 * @brief Zwraca iterator wskazujący na ostatni element listy.
 * @return Obiekt Iterator ustawiony na 'ostatni'.
 */
Iterator ListaDwukierunkowa::koniec() { 
    return Iterator(ostatni);
}


/**
 * @brief Wyświetla wszystkie elementy listy w odwrotnej kolejności, używając iteratora.
 */
void ListaDwukierunkowa::wyswietlOdwr() {
    Iterator it = koniec(); // Ustawia iterator na ostatni element
    while (it.czyJestNastepny()) {
        cout << it.pobierzDane() << " ";
        it.poprzedni(); // Przesuwa iterator do tyłu
    }
    cout << endl;
}


/**
 * @brief Zwraca iterator wskazujący na pierwszy element listy.
 * @return Obiekt Iterator ustawiony na 'pierwszy'.
 */
Iterator ListaDwukierunkowa::poczatek() { 
    return Iterator(pierwszy);
}