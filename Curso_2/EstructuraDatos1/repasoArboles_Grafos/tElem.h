//
// Created by Diego on 08/01/2024.
//

#ifndef REPASOARBOLES_GRAFOS_TELEM_H
#define REPASOARBOLES_GRAFOS_TELEM_H

typedef int tElem;

void asignarElem(tElem * e1, tElem e2);   // Asigna el valor del elemento "e2" al elemento "e1"
void mostrarElem(tElem e);              // Imprime por pantalla el elemento "e"
int filtro(tElem e);                    // Indica si un número es par o impar
int esIgual(tElem e1, tElem e2);        // Indica si dos elementos son iguales
int mayor(tElem e1, tElem e2);          // Inidca si el elemento "e2" es mayor que el elemento "e1"

#endif //REPASOARBOLES_GRAFOS_TELEM_H
