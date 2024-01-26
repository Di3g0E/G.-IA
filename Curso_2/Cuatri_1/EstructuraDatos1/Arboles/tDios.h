//
// Created by Diego on 16/11/2023.
//

#ifndef ARBOL_TDIOS_H
#define ARBOL_TDIOS_H

#include <string.h>
#include <stdio.h>
#define N 10
#define M 50


typedef struct {
    char nombre[N];
    char descripcion[M];
}tDios;

void crearDios(tDios *d, char nom[N], char descr[M]);
void asignar(tDios *info, tDios e);
void mostrarDios(tDios d);
int mismoDios(tDios a, tDios b);

#endif //ARBOL_TDIOS_H
