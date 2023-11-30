//
// Created by Diego on 28/11/2023.
//

#ifndef PRACTICA_ARBOLES_2_TCOMPETICION_H
#define PRACTICA_ARBOLES_2_TCOMPETICION_H

#include <string.h>
#define N 20

typedef struct {
    char titulo[N];
    int tiempo;
    int premio;
}tCompeticion;

void asignar(tCompeticion * dest, tCompeticion orig);

#endif //PRACTICA_ARBOLES_2_TCOMPETICION_H
