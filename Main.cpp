#include "Lista.h" // Dołaczenie nagłowka Lista.h
#include "Iterator.h" // Dołaczenie nagłowka Interator.h
#include "Factory.h" // Dołaczenie nagłowka Factory.h
#include <iostream>

using namespace std;
int main() {
    ListaDwukierunkowa* lista = Factory::utworzListe(); // tworzenie listy przez Factory

    lista->dodajNaKoniec(14); // dodawanie elementu 14 na koniec
    lista->dodajNaPoczatek(74); // dodawanie elementu 74 na początek
    lista->dodajIndex(1, 23); // dodawanie elementu 23 na indeks 1

    Iterator it = lista->poczatek(); // pobranie iteratora na początek listy

    // Wypisywanie listy
    while (it.czyJestNastepny()) {
        cout << it.pobierzDane() << " ";
        it.nastepny();
    }
    cout << endl;

    delete lista; // czyszczenie listy
    return 0;
}