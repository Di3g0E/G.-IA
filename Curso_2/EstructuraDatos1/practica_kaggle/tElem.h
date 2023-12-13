//
// Created by Diego on 12/12/2023.
//

#ifndef PRACTICA_KAGGLE_TELEM_H
#define PRACTICA_KAGGLE_TELEM_H

#include <string.h>
#include <stdio.h>

typedef struct {
    char * titulo[50];
    int tiempo;
    int premio;
}tCompet;

void asignar(tCompet * dest, tCompet orig);
void mostrarInfo(tCompet comp);

#endif //PRACTICA_KAGGLE_TELEM_H
