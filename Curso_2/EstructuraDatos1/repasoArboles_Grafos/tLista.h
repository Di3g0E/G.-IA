//
// Created by Diego on 08/01/2024.
//

#ifndef REPASOARBOLES_GRAFOS_TLISTA_H
#define REPASOARBOLES_GRAFOS_TLISTA_H

#include "tElem.h"

typedef struct nodo{
    tElem elem;
    struct nodo * sig;
    struct nodo * ant;
} tNodoList;

typedef tNodoList * tLista;

void crearListaVacia(tLista * l);               // Crea una lista vacía
void construirLista(tLista *l, tElem e);        // Añade un elemento a la lista por cabecera
void concatenar(tLista * l1, tLista l2);        // Añade la lista "l2" a la lista "l1"
void mostrarLista(tLista l);                    // Imprime la lista por terminal
int esVacia(tLista l);                          // Indica si la lista está vacía
int elemEnLista(tLista l, tElem e);             // Indica si un elem está en la lista

#endif //REPASOARBOLES_GRAFOS_TLISTA_H
