#include "Lista.h" // Dołaczenie nagłowka Lista.h
#include "Iterator.h" // Dołaczenie nagłowka Interator.h

ListaDwukierunkowa::ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {} // konstruktor


// destruktor
ListaDwukierunkowa::~ListaDwukierunkowa() { 
    Wezel* aktualny = pierwszy;
    while (aktualny) {
        Wezel* nastepny = aktualny->nastepny;
        delete aktualny;
        aktualny = nastepny;
    }
}


// Dodawanie na koniec
void ListaDwukierunkowa::dodajNaKoniec(int wartosc) {
    Wezel* nowy = new Wezel(wartosc);
    if (!ostatni) {
        pierwszy = ostatni = nowy;
    } else {
        ostatni->nastepny = nowy;
        nowy->poprzedni = ostatni;
        ostatni = nowy;
    }
}


// Dodawanie na początek
void ListaDwukierunkowa::dodajNaPoczatek(int wartosc) {
    Wezel* nowy = new Wezel(wartosc);
    if (!pierwszy) {
        pierwszy = ostatni = nowy;
    } else {
        nowy->nastepny = pierwszy;
        pierwszy->poprzedni = nowy;
        pierwszy = nowy;
    }
}


// Dodawanie na miejsce indeksu
void ListaDwukierunkowa::dodajIndex(int indeks, int wartosc) {
    if (indeks <= 0) {
        dodajNaPoczatek(wartosc);
        return;
    }
    Wezel* aktualny = pierwszy;
    for (int i = 0; i < indeks - 1 && aktualny; ++i)
        aktualny = aktualny->nastepny;

    if (!aktualny) {
        dodajNaKoniec(wartosc);
        return;
    }

    Wezel* nowy = new Wezel(wartosc);
    nowy->nastepny = aktualny->nastepny;
    nowy->poprzedni = aktualny;

    if (aktualny->nastepny)
        aktualny->nastepny->poprzedni = nowy;
    else
        ostatni = nowy;

    aktualny->nastepny = nowy;
}

// Pobranie iteratora na początek listy
Iterator ListaDwukierunkowa::poczatek() { 
    return Iterator(pierwszy);
}