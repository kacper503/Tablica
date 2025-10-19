#pragma once // Uruchomienie tylko raz
#include "Lista.h" // Dołaczenie nagłowka Lista.h


// klasa Iterator
class Iterator {
private:
    ListaDwukierunkowa::Wezel* aktualny;

public:
    Iterator(ListaDwukierunkowa::Wezel* wezel) : aktualny(wezel) {}
    bool czyJestNastepny() const { return aktualny != nullptr; }
    int pobierzDane() const { return aktualny->dane; }
    void nastepny() { if (aktualny) aktualny = aktualny->nastepny; }
};