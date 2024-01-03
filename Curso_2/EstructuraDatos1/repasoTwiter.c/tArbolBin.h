//
// Created by Diego on 03/01/2024.
//

#ifndef REPASOTWITER_C_TARBOLBIN_H
#define REPASOTWITER_C_TARBOLBIN_H

#include "tHashtag.h"
#include "tListaTweets.h"

typedef struct nodo{
    tHashtag hashtag;
    tListaTweets l;
    struct nodo sig;
    struct nodo ant;
} tNodoAr;

typedef tNodoAr * tArbol;

void crearArbolVacio(tArbol * a);
void construirArbol(tArbol * a, tHashtag h);               // El árbol debe estar ordenado por orden alfabético y únicamente añadirá hashtags nuevos
void etiquetarTweets(tArbol * a, tHashtag h, tTweet t);     // Se añadirán los tweets a las listas de hashtags en los que aparezcan
int consultas(tArbol a, tHashtag h);                        // Se mostrarán por pantalla los tweets que contengan el hashtag mencionado


#endif //REPASOTWITER_C_TARBOLBIN_H
