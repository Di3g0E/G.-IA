#include <math.h>
#include <stdio.h>
#include "tComplejos.h"

int main(){
    tComplejo I[4];
    int V0 = 220, v = 50, C = 1.2, L = 3, R = 5;
    tComplejo V, Z_r, Z_l, Z_c, w;
    V = crearComplejo(V0, 0);
    w = crearComplejo(2 * M_PI * v, 0);
    Z_r = crearComplejo(R, 0);
    Z_l = multiplicar(w, crearComplejo(L, 0));
    Z_c = dividir(crearComplejo(0, -1), multiplicar(w, crearComplejo(C, 0)));
    tComplejo Z[4] = {crearComplejo(0, 0), Z_r, Z_l, Z_c};
    tComplejo sumacion = crearComplejo(0, 0);


    for (int i = 0; i < 4; ++i) {
        sumacion = sumar(sumacion, Z[i]);
        I[i] = dividir(V, sumacion);
        printf("%f", I[i]);
    }
}
