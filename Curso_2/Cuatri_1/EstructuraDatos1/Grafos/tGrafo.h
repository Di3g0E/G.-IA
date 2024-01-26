//
// Created by Diego on 28/11/2023.
//

#ifndef GRAFOS_TGRAFO_H
#define GRAFOS_TGRAFO_H

#include "tElemento.h"
#include <stdio.h>
#include <stdlib.h>

struct NodoAdy{
    tElem info;
    struct NodoAdy * sig;
};
typedef struct NodoAdy * listaAdy;

struct Nodolista{
    tElem info;
    listaAdy * ady;
    struct Nodolista * sig;
};
typedef struct NodoLista * tGrafo;


void crearGrafoVacio(tGrafo *g);
void insertarNodo(tGrafo *g, tElem *n);
void mostrarVertices(tGrafo g);

#endif //GRAFOS_TGRAFO_H
