//
// Created by Diego on 08/01/2024.
//

#include "tGrafo.h"
#include <stdio.h>
#include <stdlib.h>

void crearGrafoVacio(tGrafo *g) {
    *g = NULL;
}


void construirGrafo(tGrafo *g, tElem orig, tElem dest) {
    if (!esVacio(*g)) {
        tGrafo *aux = g;
        while (!esIgual((*aux)->elem, orig) && aux != NULL){
            *aux = (*aux)->sig;
        }
        if (!esIgual((*aux)->elem, orig)){
            tNodoGr * new = (tNodoGr *) malloc(sizeof (tNodoGr));
            asignarElem(&new->elem, orig);
            construirLista(&new->l, dest);
            new->sig = (*aux)->sig;
            (*aux)->sig = new;
        } else {
            construirLista(&(*aux)->l, dest);
        }
    } else {
        tNodoGr * new = (tNodoGr *) malloc(sizeof (tNodoGr));
        asignarElem(&new->elem, orig);
        construirLista(&new->l, dest);
        new->sig = NULL;
        *g = new;
    }
}


void mostrarVertices(tGrafo g);


int esVacio(tGrafo g);


int elemEnGrafo(tGrafo g, tElem e);