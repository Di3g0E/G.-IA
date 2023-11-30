//
// Created by Diego on 28/11/2023.
//

#include "tGrafo.h"

void crearGrafoVacio(tGrafo *g){
    *g = NULL;
}


void insertarNodo(tGrafo *g, tElem *n){
    struct Nodolista * aux = (struct Nodolista *) malloc(sizeof (struct Nodolista));
    asignar(&(aux->info), n);
    aux->sig = NULL;
    *g = aux;
}


void mostrarVertices(tGrafo g);