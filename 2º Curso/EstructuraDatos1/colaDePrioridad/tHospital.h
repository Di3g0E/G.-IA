//
// Created by Diego on 07/11/2023.
//

#ifndef PRACTICA_4_THOSPITAL_H
#define PRACTICA_4_THOSPITAL_H

#include <stdio.h>
#include <stdlib.h>
#include "tPaciente.h"

typedef struct Nodo{
    tElem info;
    struct Nodo* ant;
    struct Nodo* sig;
}tNodo;

typedef struct {
    int numCamas;
    tNodo * ini;
    tNodo * fin;
}tHospital;

void crearHospitalVacio(tHospital* hospital, int camas_disponibles);
void insertarEnHospital(tHospital* hospital, tElem paciente);
void consultarPrimero(tHospital hospital);
void quitarPrimero(tHospital* hospital);
int esHospitalVacio(tHospital hospital);


#endif //PRACTICA_4_THOSPITAL_H
