//
// Created by Diego on 05/10/2023.
//

#ifndef ESTRUCTURADATOS1_TCOMPLEJOS_H
#define ESTRUCTURADATOS1_TCOMPLEJOS_H

typedef struct {
    int re;
    int im;
} tComplejo;

// Operaciones constructoras generadoras:
tComplejo crearComplejo(int re, int im);

// Operaciones constructoras selectoras:
int obtenerReal(tComplejo complejo);
int obtenerImaginario(tComplejo complejo);

// Operaciones constructoras no selectoras:
float calcularModulo(tComplejo complejo);

// Operaciones constructoras no generadoras:
tComplejo conjugado(tComplejo complejo);
tComplejo sumar(tComplejo complejo_UNO, tComplejo complejo_DOS);
tComplejo restar(tComplejo complejo_UNO, tComplejo complejo_DOS);
tComplejo multiplicar(tComplejo complejo_UNO, tComplejo complejo_DOS);
tComplejo dividir(tComplejo complejo_UNO, tComplejo complejo_DOS);
tComplejo I();

#endif //ESTRUCTURADATOS1_TCOMPLEJOS_H
