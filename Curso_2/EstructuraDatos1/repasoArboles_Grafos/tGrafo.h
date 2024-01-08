//
// Created by Diego on 08/01/2024.
//

#ifndef REPASOARBOLES_GRAFOS_TGRAFO_H
#define REPASOARBOLES_GRAFOS_TGRAFO_H

#include "tElem.h"
#include "tLista.h"

typedef struct nodoGr{
    tElem elem;
    tLista l;
    struct nodoGr * sig;
} tNodoGr;

typedef tNodoGr * tGrafo;

void crearGrafoVacio(tGrafo *g);                            // Crea un grafo vacío
void construirGrafo(tGrafo *g, tElem orig, tElem dest);     // Añade una conexión al grafo
void mostrarVertices(tGrafo g);                             // Muestra el grafo por terminal
int esVacio(tGrafo g);                                      // Indica si el grafo esta vacío
int elemEnGrafo(tGrafo g, tElem e);                         // Indica si el elemento "e" está en el grafo

#endif //REPASOARBOLES_GRAFOS_TGRAFO_H
