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
    char arNom[10], diNom[10];
    strcpy(arNom, a->info.nombre);
    strcpy(diNom, d.nombre);
    if (strcmp(arNom, diNom) == 0){
        return 1;
    } else {
        if (existeDios(a->izq, d) && a != NULL) {
            return existeDios(a->izq, d);
        }
        if (existeDios(a->der, d) && a != NULL){
            return existeDios(a->der, d);
        }
    }
    return 0;
}


int esPadre(tArbol p, tArbol h){
    return mismoDios(p->izq->info, h->info) || mismoDios(p->der->info, h->info);
}


int mostrarArbol(tArbol a){
    mostrarDios(a->info);
    if (a->izq != NULL){
        mostrarArbol(a->izq);
    } else {
        if (a->der != NULL) {
            mostrarArbol(a->der);
        }
    }
}