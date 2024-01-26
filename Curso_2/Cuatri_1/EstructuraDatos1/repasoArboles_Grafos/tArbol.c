//
// Created by Diego on 08/01/2024.
//

#include "tArbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <minmax.h>

void crearArbolVacio(tArbol * a){
    *a = NULL;
}


void construirArbol(tArbol * a, tArbol i, tElem r, tArbol d){
    tNodoAr * new= (tNodoAr *) malloc (sizeof (tNodoAr));
    asignarElem(&new->raiz, r);
    new->izq = i;
    new->der = d;
    *a = new;
}


void mostrarArbolPreorden(tArbol a){
    if (a != NULL) {
        mostrarElem(a->raiz);
        mostrarArbolPreorden(a->izq);
        mostrarArbolPreorden(a->der);
    }
}


void mostrarArbolInorden(tArbol a) {
    if (a != NULL) {
        mostrarArbolInorden(a->izq);
        mostrarElem(a->raiz);
        mostrarArbolInorden(a->der);
    }
}


void mostrarArbolPostorden(tArbol a) {
    if (a != NULL) {
        mostrarArbolPostorden(a->izq);
        mostrarArbolPostorden(a->der);
        mostrarElem(a->raiz);
    }
}


int altura(tArbol a){
    int sol;
    if (a == NULL) {
        return 0;
    } else {
        return 1 + max(altura(a->izq), altura(a->der));
    }
}


int numNodos(tArbol a){
    if (esVacio(a)) {
        return 0;
    } else {
        return 1 + numNodos(a->izq) + numNodos(a->der);
    }
}


int esVacio(tArbol a){
    return a == NULL;
}


int esEquilibrado(tArbol a){
    return (altura(a->izq) - altura(a->der) >= -1 && altura(a->izq) - altura(a->der) <= 1);
}


int esHoja(tArbol a) {
    return (a->izq == NULL && a->der == NULL);
}


int nivel(tArbol a, tElem e){
    while (!esIgual(a->raiz, e)){
        if (mayor(a->raiz, e)){
            a = a->der;
        } else {
            a = a->izq;
        }
    }
    altura(a);
}