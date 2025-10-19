#include <iostream>
#include "Lista.h"
#include "Iterator.h"
#include "Factory.h"
using namespace std;

int main() {
    ListaDwukierunkowa* lista = Factory::utworzListe();

    lista->dodajNaKoniec(14);
    lista->dodajNaPoczatek(74);
    lista->dodajIndex(1, 23);

    Iterator it = lista->poczatek();

    // Wypisywanie listy
    while (it.czyJestNastepny()) {
        cout << it.pobierzDane() << " ";
        it.nastepny();
    }
    cout << endl;

    delete lista;
    return 0;
}