//
// Created by Diego on 03/01/2024.
//

#include "tGrafo.h"
#include <stdio.h>
#include <stdlib.h>

void crearArbolVacio(tArbol * a){
    *a = NULL;
}


void construirArbol(tArbol * a, tHashtag h){
    while (*a != NULL || &(*a)->sig != NULL || mismoHashtag((*a)->hashtag, h) != 1){
        *a = &(*a)->sig;
    }
    if (mismoHashtag((*a)->hashtag, h) == 1){
        tArbol new = (tArbol) malloc(sizeof (tNodoAr)); // Creo un nuevo nodo (en memoria dinámica)
        nombrarHashtag(new->hashtag, h);                // Copio el nuevo hashtag en el campo hashtag del nuevo nodo
        crearListaVacia(&new->l);                        // Creo una lista de tweets vacía para el hashtag
        new->sig = &(*a)->sig;                          // Ahora apunta al siguiente nodo de la lista
        new->ant = &(*a)->ant;                          // Ahora apunta al anterior nodo de la lista
        *a = &(*a)->ant;
        &(*a)->sig = new;                               // Apunto con el nodo anterior al recién creado
    }
}


void etiquetarTweets(tArbol * a, tHashtag h, tTweet t){
    while (*a != NULL || &(*a)->sig != NULL || mismoHashtag((*a)->hashtag, h) == 0){
        *a = &(*a)->sig;
    }
    if (mismoHashtag((*a)->hashtag, h) == 0){
        aniadirTweet(&(*a)->l, t);
    }
}


int consultas(tArbol a, tHashtag h){
    while (a != NULL || &(a)->sig != NULL || mismoHashtag(a->hashtag, h) == 0){
        a = &(a)->sig;
    }
    if (mismoHashtag(a->hashtag, h) == 0){
        imprimirLista(a->l);
    }
}