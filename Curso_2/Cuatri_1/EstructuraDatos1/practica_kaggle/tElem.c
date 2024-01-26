//
// Created by Diego on 12/12/2023.
//

#include "tElem.h"

void asignar(tCompet * dest, tCompet orig){
    dest->titulo[0] = strdup(orig.titulo[0]);
    dest->premio = orig.premio;
    dest->tiempo = orig.tiempo;
}


void mostrarInfo(tCompet comp){
    printf("%s\t", *comp.titulo);
    printf("%d\t", comp.tiempo);
    printf("%d\n", comp.premio);
}