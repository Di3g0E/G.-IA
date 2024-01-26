//
// Created by Diego on 03/01/2024.
//

#ifndef REPASOTWITER_C_TLISTATWEETS_H
#define REPASOTWITER_C_TLISTATWEETS_H

#include "tTweet.h"

typedef struct nodoTw{
    tTweet tweet;
    struct nodoTw sig;
    struct nodoTw ant;
} tNodoTweet;

typedef tNodoTweet * tListaTweets;

void crearListaVacia(tListaTweets * l);
void aniadirTweet(tListaTweets * l, tTweet t);
void imprimirLista(tListaTweets l);

#endif //REPASOTWITER_C_TLISTATWEETS_H
