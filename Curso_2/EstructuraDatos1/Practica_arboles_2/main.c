#include <stdio.h>
#include "tArbol.h"

int main() {
    tArbol a, izq, der;
    tCompeticion competicion = {"Competicion_1", 12, 1000};
    crearArbolVacio(&a);
    crearArbolVacio(&izq);
    crearArbolVacio(&der);
    construirArbol(izq, &a, der, competicion);

    return 0;
}
