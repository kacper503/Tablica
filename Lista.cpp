#include <iostream>

using namespace std;


// Klasa listy dwukierunkowej
class ListaDwukierunkowa {
    private: 
        struct Wezel {
            int dane;
            Wezel* poprzedni;
            Wezel* nastepny;
            Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
        };

        Wezel* pierwszy; //pierwszy element
        Wezel* ostatni; // ostatni element

    public:
    //Konstruktor
    ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {}

    //Destruktor
    ~ListaDwukierunkowa() {
        Wezel* aktualny = pierwszy;
        while (aktualny) {
            Wezel* nastepny = aktualny->nastepny;
            delete aktualny;
            aktualny = nastepny;
        }
    }
};