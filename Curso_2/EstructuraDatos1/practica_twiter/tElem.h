//
// Created by Diego on 14/12/2023.
//

#ifndef PRACTICA_TWITER_TELEM_H
#define PRACTICA_TWITER_TELEM_H

#include "listaEnlazadaSimple.h"

typedef struct {
    char hashtag;       // Almacena un solo hashtag
    tLista tweets;      // Almacena una lista dinámica de tweets
}tElem;


void asignar(tElem * dest, tElem orig);


#endif //PRACTICA_TWITER_TELEM_H
