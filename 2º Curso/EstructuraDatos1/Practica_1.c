#include <stdio.h>
#include <malloc.h>

#define N_ARRAY 200000
#define N_PUNTERO 20000

void subprogramaArray(int contenedor[], int num); // El subprograma guarda en memoria una copia de "contenedor[]" hasta que salte el error "full stack"
void subprogramaPuntero(int *puntContenedor, int num);  // El subprograma reserva el espacio de "contenedor[]" en memoria dinámica (heap) hasta que se queda sin espacio y salta el error "full heap"

int main() {
    int contenedor[N_PUNTERO];
    int num = 1000000000000;        // 1 000 000 000 000, un billón
    int *puntContenedor = (int *) malloc(N_PUNTERO * sizeof(int));

    int prog;
    printf("Selecciona el programa a realizar: \n"
           "1. Reservar el espacio de memoria en Stack\n"
           "2. Reservar el espacio de memoria en Heap \n"
           "Introduzca el numero del programa:");
    scanf("%d", &prog);

    switch (prog) {
        case 1:
            subprogramaArray(contenedor, num);
            break;
        case 2:
            subprogramaPuntero((int *) puntContenedor, num);
            break;
        default:
            printf("\n No se ha seleccionado nada.");
    }

    return 0;
}

//  Tarda más en saltar el error "full heap" por lo que el heap debe tener más capacidad de almacenamiento que el stack

void subprogramaArray(int contenedor[], int num){
    if (contenedor[N_ARRAY] <= 0) {
        printf("Termina satisfactoriamente");
    }
    else {
        subprogramaArray(&contenedor[N_ARRAY], num - 1);
    }
}

void subprogramaPuntero(int *puntContenedor, int num){
    if (num == NULL) {
        printf("Termina satisfactoriamente");
        free(puntContenedor);
        return;
    }
    else {
        int *nuevoPuntero = malloc(N_PUNTERO * sizeof(int));
        subprogramaPuntero(puntContenedor, num-1);
        free(nuevoPuntero);
    }
}
