//
// Created by Diego on 03/01/2024.
//

#include "tListaTweets.h"
#include <stdio.h>
#include <stdlib.h>

void crearListaVacia(tListaTweets * l){
    *l = NULL;
}


void aniadirTweet(tListaTweets * l, tTweet t){
    while (*l != NULL || &(*l)->sig != NULL || mismoTweet((*l)->tweet, t) != 1){
        *l = &(*l)->sig;
    }
    if (mismoTweet((*l)->tweet, t) == 1){
        tListaTweets new = (tListaTweets) malloc(sizeof (tNodoTweet));  // Creo un nuevo nodo (en memoria dinámica)
        nombrarTweet(new->tweet, t);                                    // Copio el nuevo tweet en el campo tweet del nuevo nodo
        new->sig = &(*l)->sig;                                          // Ahora apunta al siguiente nodo de la lista
        new->ant = &(*l)->ant;                                          // Ahora apunta al anterior nodo de la lista
        *l = &(*l)->ant;
        &(*l)->sig = new;                                               // Apunto con el nodo anterior al recién creado
    }
}


void imprimirLista(tListaTweets l){
    while (l != NULL){
        printf("%s\n", l->tweet);
        l = l->sig;
    }
}