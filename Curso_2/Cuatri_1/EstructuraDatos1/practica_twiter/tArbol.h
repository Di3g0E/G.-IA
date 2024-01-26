//
// Created by Diego on 14/12/2023.
//

#ifndef PRACTICA_TWITER_TARBOL_H
#define PRACTICA_TWITER_TARBOL_H

#include "tElem.h"

typedef struct NodoAr{
    tElem info;
    struct NodoAr * izq;
    struct NodoAr * der;
}tNodoAr;

typedef tNodoAr * tArbol;


void crearArbolVacio(tArbol *a);
void construirArbol(tArbol *a, tElem e);
void mostrarTweets(tArbol a, tElem e);
void consultaHashtag(tArbol a, tElem e);
int esVacio(tArbol a);


#endif //PRACTICA_TWITER_TARBOL_H
