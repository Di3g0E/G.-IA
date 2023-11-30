//
// Created by Diego on 28/11/2023.
//

#include "tArbol.h"

void crearArbolVacio(tArbol * a){
    *a = NULL;
}


void construirArbol(tArbol izq, tArbol * a, tArbol der, tCompeticion competicion){
    if (esVacio(&a) && (*a)->info.premio > competicion.premio){
        construirArbol(izq->izq, &izq, izq->der, competicion);
    } else{
        if (esVacio(&a) && (*a)->info.premio < competicion.premio){
            construirArbol(der->izq, &der, der->der, competicion);
        } else {
            asignar(&(*a)->info, competicion);
            (*a)->izq = &izq;
            (*a)->der = &der;
        }
    }
}


int esVacio(tArbol a){return (*a == NULL);}