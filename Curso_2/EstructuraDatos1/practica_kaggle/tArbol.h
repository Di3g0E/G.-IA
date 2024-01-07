//
// Created by Diego on 12/12/2023.
//

#ifndef PRACTICA_KAGGLE_TARBOL_H
#define PRACTICA_KAGGLE_TARBOL_H

#include "tElem.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    tCompet info;
    struct Nodo * izq;
    struct Nodo * der;
}tNodo;

typedef tNodo * tArbol;


void crearArbolVacio(tArbol * a);
void aniadirNodo(tArbol *a, tCompet c);
void imprimir(tArbol a);
void peorPremio(tArbol a);
void eliminarNodo(tArbol * a, int premio);
int esVacio(tArbol a);

#endif //PRACTICA_KAGGLE_TARBOL_H
