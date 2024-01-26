//
// Created by Diego on 16/11/2023.
//

#ifndef ARBOL_TARBOL_H
#define ARBOL_TARBOL_H

#include <stdlib.h>
#include "tDios.h"


typedef struct Nodo {
    tDios info;
    struct Nodo *izq;
    struct Nodo *der;
}tNodo;

typedef tNodo *tArbol;


void crearArbolBinVacio(tArbol * a);
void construirArbolB(tArbol *a, tArbol *izq, tArbol *der, tDios r);
int existeDios(tArbol a, tDios d);
int esPadre(tArbol p, tArbol h);
int mostrarArbol(tArbol a);


#endif //ARBOL_TARBOL_H
