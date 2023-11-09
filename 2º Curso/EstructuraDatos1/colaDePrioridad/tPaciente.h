//
// Created by Diego on 07/11/2023.
//

#ifndef PRACTICA_4_TPACIENTE_H
#define PRACTICA_4_TPACIENTE_H

#include <stdio.h>
#include <string.h>

typedef struct paciente{
    int exp;
    char nombre[20];
    int edad;
    char dolecia[50];
}tElem;

void asignarInfo(tElem paciente_ini, tElem* paciente_dest);
void mostrarPaciente(tElem paciente);

#endif //PRACTICA_4_TPACIENTE_H
