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


// Usuwanie z końca
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
            pierwszy = nullptr; 
        }
    }
    delete doUsuniecia;
}


// Usuwanie z początku
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
            ostatni = nullptr; 
        }
    }
    delete doUsuniecia;
}


// Usuwanie z miejsca indeksu
void ListaDwukierunkowa::usunZIndex(int indeks) {
    if (!pierwszy) {
        return; // Lista pusta
    }

    if (indeks <= 0) {
        usunZPoczatku();
        return;
    }

    Wezel* aktualny = pierwszy;
    for (int i = 0; i < indeks && aktualny; ++i) {
        aktualny = aktualny->nastepny;
    }

    if (!aktualny) {
        return; 
    }

    if (aktualny->poprzedni) {
        aktualny->poprzedni->nastepny = aktualny->nastepny;
    } else {
        pierwszy = aktualny->nastepny;
    }

    if (aktualny->nastepny) {
        aktualny->nastepny->poprzedni = aktualny->poprzedni;
    } else {
        ostatni = aktualny->poprzedni;
    }

    delete aktualny;
}

// Pobranie iteratora na początek listy
Iterator ListaDwukierunkowa::poczatek() { 
    return Iterator(pierwszy);
}