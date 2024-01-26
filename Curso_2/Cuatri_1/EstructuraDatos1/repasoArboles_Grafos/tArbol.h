//
// Created by Diego on 08/01/2024.
//

#ifndef REPASOARBOLES_GRAFOS_TARBOL_H
#define REPASOARBOLES_GRAFOS_TARBOL_H

#include "tElem.h"
#include "tLista.h"

typedef struct nodoAr {
    tElem raiz;
    struct nodoAr * izq;
    struct nodoAr * der;
} tNodoAr;

typedef tNodoAr * tArbol;

void crearArbolVacio(tArbol * a);                                       // Crea un árbol vacío, que apunta a NULL
void construirArbol(tArbol * a, tArbol i, tElem r, tArbol d);           // Añade un nodo al árbol "a"
void mostrarArbolPreorden(tArbol a);                                    // Muestra el árbol por terminal de forma preorder
void mostrarArbolInorden(tArbol a);                                     // Muestra el árbol por terminal de forma inorder
void mostrarArbolPostorden(tArbol a);                                   // Muestra el árbol por terminal de forma postorder
int altura(tArbol a);                                                   // Devuelve la altura del árbol "a"
int numNodos(tArbol a);                                                 // Devuelve el número de nodos del árbol "a"
int esVacio(tArbol a);                                                  // Indica si el árbol "a" es vacío o no
int esEquilibrado(tArbol a);                                            // Indica si el árbol "a" es equilibrado o no
int filtrarArbol(tArbol a, tLista l);                                   // Devuelve una lista con las raíces del árbol que pasan el filtro
int esHoja(tArbol a);                                                   // Indica si el árbol "a" es una hoja o no (sus ramas izq. y der. son NULL)
int nivel(tArbol a, tElem e);                                           // Indica el nivel en el que se encuentra el elemento "e"

#endif //REPASOARBOLES_GRAFOS_TARBOL_H
