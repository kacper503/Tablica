/**
 * @file Main.cpp
 * @brief Główny plik programu demonstrujący użycie ListaDwukierunkowa i Iterator.
 */

#include "Lista.h" // Dołaczenie nagłowka Lista.h
#include "Iterator.h" // Dołaczenie nagłowka Interator.h
#include "Factory.h" // Dołaczenie nagłowka Factory.h
#include <iostream>

using namespace std;

/**
 * @brief Główna funkcja programu.
 * @return 0 w przypadku pomyślnego zakończenia.
 */
int main() {
    // Tworzenie listy przez Factory
    ListaDwukierunkowa* lista = Factory::utworzListe(); 

    // Operacje dodawania
    lista->dodajNaKoniec(14); // dodawanie elementu 14 na koniec
    lista->dodajNaPoczatek(74); // dodawanie elementu 74 na początek
    lista->dodajIndex(1, 23); // dodawanie elementu 23 na indeks 1
    lista->dodajNaKoniec(44); // dodawanie elementu 44 na koniec

    // Pobranie iteratora na początek listy
    Iterator it = lista->poczatek(); 

    // Wypisywanie listy przy użyciu iteratora
    cout << "lista standardowa:" << endl;

    while (it.czyJestNastepny()) {
        cout << it.pobierzDane() << " ";
        it.nastepny();
    }
    cout << endl;

    // Wyświetlanie w odwrotnej kolejności
    cout << "Lista w odwrotnej kolejnosci: ";
    lista->wyswietlOdwr();
    cout << endl;

    // Testowanie nawigacji iteratora
    cout << "testowanie nastepny i poprzedni:" << endl;
    it = lista->poczatek();
    it.nastepny();

    // Testowanie nastepny()
    Iterator temp_next = it; // tworzenie tymczasowego iteratora
    temp_next.nastepny(); // przesuwanie do następnego elementu
    if (temp_next.czyJestNastepny()) {
        cout << "Nastepny element po " << it.pobierzDane() << " to: " << temp_next.pobierzDane() << endl; // Powinno być 14
    } else {
        cout << "Element " << it.pobierzDane() << " jest ostatni." << endl;
    }

    // Testowanie poprzedni()
    Iterator temp_prev = it; // tworzenie tymczasowego iteratora
    temp_prev.poprzedni(); // przesuwanie do poprzedniego elementu
    if (temp_prev.czyJestNastepny()) {
        cout << "Poprzedni element przed " << it.pobierzDane() << " to: " << temp_prev.pobierzDane() << endl; // Powinno być 74
    } else {
        cout << "Element " << it.pobierzDane() << " jest pierwszy." << endl;
    }
    cout << endl;

    // Operacje usuwania
    lista->usunZPoczatku(); // Usuwa z pierwszego miejsca
    lista->usunZIndex(1); // Usuwa z indeksu 1 (nowa lista: 23, 14, 44. Usuwa 14)
    lista->usunZKonca(); // Usuwa z końca (nowa lista: 23)

    // Dodanie elementu i ponowne wyświetlenie
    lista->dodajNaPoczatek(99); // dodawanie elementu 99 na początek (lista: 99, 23)

    it = lista->poczatek(); 
    cout << "Lista po usunięciach i dodaniu:" << endl;
    while (it.czyJestNastepny()) {
        cout << it.pobierzDane() << " ";
        it.nastepny();
    }
    cout << endl;

    delete lista; // czyszczenie listy (wywołanie destruktora)
    return 0;
}