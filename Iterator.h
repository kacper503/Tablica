#pragma once
#include "Lista.h"
#include <iostream>
using namespace std;

class Iterator {
private:
    ListaDwukierunkowa::Wezel* aktualny;

public:
    Iterator(ListaDwukierunkowa::Wezel* wezel) : aktualny(wezel) {}
    bool czyJestNastepny() const { return aktualny != nullptr; }
    int pobierzDane() const { return aktualny->dane; }
    void nastepny() { if (aktualny) aktualny = aktualny->nastepny; }
};