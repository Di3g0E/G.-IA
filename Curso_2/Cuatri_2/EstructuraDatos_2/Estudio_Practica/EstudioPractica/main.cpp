#include <iostream>
#include "ListaEnlazadaSimple.h"

int main() {
    ListaEnlazadaSimple l;
    l.insertar(3);
    l.insertar(2);
    l.insertar(4);
    l.insertar(3);

    l.imprimir();

    l.mostrarPrimero();

    l.resto();

    l.imprimir();
    return 0;
}
