#include <stdio.h>
#include <malloc.h>

void subprogramaArray(int contenedor[], int num); // El subprograma guarda en memoria una copia de "contenedor[]" hasta que salte el error "full stack"
void subprogramaPuntero(int *puntContenedor, int num);  // El subprograma reserva el espacio de "contenedor[]" en memoria dinámica (heap) hasta que se queda sin espacio y salta el error

int main() {
    int contenedor[20000];
    int num = 1000000000;
    int *puntContenedor = (int *) malloc(20000 * sizeof(int));

    subprogramaArray(contenedor, num);
    subprogramaPuntero((int *) puntContenedor, num);

    return 0;
}


void subprogramaArray(int contenedor[], int num){
    if (contenedor[20000] <= 0) {return;
    }
    subprogramaArray(&contenedor[20000], num - 1);
}

void subprogramaPuntero(int *puntContenedor, int num){
    if (num == NULL) {
        free(puntContenedor);
        return;
    }
    int *nuevoPuntero = malloc(20000 * sizeof(int));
    subprogramaPuntero(puntContenedor, num-1);
    free(nuevoPuntero);
}
