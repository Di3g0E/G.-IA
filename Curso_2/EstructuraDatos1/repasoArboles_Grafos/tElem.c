//
// Created by Diego on 08/01/2024.
//

#include "tElem.h"
#include <stdio.h>

void asignarElem(tElem * e1, tElem e2){
    *e1 = e2;
}


void mostrarElem(tElem e){
    printf("\t%d", e);
}


int filtro(tElem e){
    return (e % 2 == 0);
}


int esIgual(tElem e1, tElem e2){
    return e1 == e2;
}


int mayor(tElem e1, tElem e2){
    return e2 > e1;
}