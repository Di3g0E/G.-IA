//
// Created by Diego on 08/01/2024.
//

#include "tLista.h"
#include <stdio.h>
#include <stdlib.h>

void crearListaVacia(tLista * l) {
    *l == NULL;
}


void construirLista(tLista *l, tElem e) {
    tNodoList * new = (tNodoList*) malloc (sizeof (tNodoList));
    if (!elemEnLista(&(*l)->elem, e)){
        asignarElem(&new->elem, e);
        new->sig = *l;
        new->ant = NULL;
        *l = new;
    }
}


void concatenar(tLista * l1, tLista l2) {
    while (l2 != NULL){
        construirLista(l1, l2->elem);
        l2 = l2->sig;
    }
}


void mostrarLista(tLista l){
    while (l != NULL){
        mostrarElem(l->elem);
        l = l->sig;
    }
}


int esVacia(tLista l){
    return l == NULL;
}


int elemEnLista(tLista l, tElem e){
    if (!esVacia(l)){
        while (l != NULL || esIgual(l->elem, e)){
            l = l->sig;
        }
        return esIgual(l->elem, e);
    }
    return 0;
}