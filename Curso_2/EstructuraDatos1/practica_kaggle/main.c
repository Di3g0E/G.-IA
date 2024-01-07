#include <stdio.h>
#include "tGrafo.h"

int main() {
    tArbol a;

    // Ejemplos
    tCompet c_1 = {.titulo = {"Competencia_A"}, .tiempo = 120, .premio = 1000};
    tCompet c_2 = {.titulo = {"Competencia_B"}, .tiempo = 90, .premio = 1500};
    tCompet c_3 = {.titulo = {"Competencia_C"} , .tiempo = 150, .premio = 800};
    tCompet c_4 = {.titulo = {"Competencia_D"}, .tiempo = 110, .premio = 1200};
    tCompet c_5 = {.titulo = {"Competencia_E"}, .tiempo = 75, .premio = 1800};
    tCompet c_6 = {.titulo = {"Competencia_F"}, .tiempo = 130, .premio = 950};
    tCompet c_7 = {.titulo = {"Competencia_G"}, .tiempo = 100, .premio = 1600};
    tCompet c_8 = {.titulo = {"Competencia_H"}, .tiempo = 85, .premio = 1400};
    tCompet c_9 = {.titulo = {"Competencia_I"}, .tiempo = 120, .premio = 1100};

    crearArbolVacio(&a);

    aniadirNodo(&a, c_1);
    aniadirNodo(&a, c_2);
    aniadirNodo(&a, c_3);
    aniadirNodo(&a, c_4);
    aniadirNodo(&a, c_5);
    aniadirNodo(&a, c_6);
    aniadirNodo(&a, c_7);
    aniadirNodo(&a, c_8);
    aniadirNodo(&a, c_9);

    peorPremio(a);

    printf("\n");
    imprimir(a);

    eliminarNodo(&a, 1800);

    printf("\n");
    imprimir(a);

    return 0;
}
