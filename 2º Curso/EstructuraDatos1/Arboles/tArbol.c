//
// Created by Diego on 16/11/2023.
//

#include "tArbol.h"

void crearArbolBinVacio(tArbol * a){
    *a = NULL;
}


void construirArbolB(tArbol *a, tArbol *izq, tArbol *der, tDios r){
    *a = (tArbol) malloc(sizeof (tNodo));
    asignar(&((*a)->info), r);
    (*a)->izq = *izq;
    (*a)->der = *der;
}


int existeDios(tArbol a, tDios d){
    if (a->info.nombre == d.nombre){
        return 1;
    } else {
        if (existeDios(a->izq, d)) {
            return existeDios(a->izq, d);
        }
        if (existeDios(a->der, d)){
            return existeDios(a->der, d);
        }
    }
    return 0;
}