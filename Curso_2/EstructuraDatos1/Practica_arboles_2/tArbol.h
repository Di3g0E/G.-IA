//
// Created by Diego on 28/11/2023.
//

#ifndef PRACTICA_ARBOLES_2_TARBOL_H
#define PRACTICA_ARBOLES_2_TARBOL_H

#include "tCompeticion.h"

typedef struct Nodo{
    tCompeticion info;
    struct Nodo * izq;
    struct Nodo * der;
}tNodo;

typedef tNodo * tArbol;

void crearArbolVacio(tArbol * a);
void construirArbol(tArbol izq, tArbol * a, tArbol der, tCompeticion competicion);
int esVacio(tArbol a);

#endif //PRACTICA_ARBOLES_2_TARBOL_H
