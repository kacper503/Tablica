#pragma once
#include "Lista.h"

class Factory {
public:
    static ListaDwukierunkowa* utworzListe() {
        return new ListaDwukierunkowa();
    }
};