//
// Created by Diego on 14/12/2023.
//

#include "tArbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearArbolVacio(tArbol *a){
    *a = NULL;
}


void construirArbol(tArbol *a, tElem e){
    if (esVacio(*a)){
        *a = (tNodoAr *) malloc(sizeof (tNodoAr));
        asignar(&(*a)->info, e);
        (*a)->izq = NULL;
        (*a)->der = NULL;
    } else {
        if (strcmp((*a)->info.tweets, e.tweets) == -1){
            construirArbol(&(*a)->izq, e);
        } else {
            construirArbol(&(*a)->der, e);
        }
    }

}


void mostrarTweets(tArbol a, tElem e){

}
void consultaHashtag(tArbol a, tElem e);
int esVacio(tArbol a){
    return (a == NULL);
}