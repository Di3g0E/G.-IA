#include <stdio.h>
#include <time.h>
#include <malloc.h>

int N = 2147483647; // Tamaño del array

int busquedaSecuencial(int *array, int tam, int elem);
int busquedaBinaria(int *array, int tam, int elem);

int main() {
    int *array = (int *)malloc(sizeof(int) * N); // Reservar memoria para el array
    int elemento_a_buscar = 42; // Elemento que deseas buscar

    // Medir el tiempo de ejecución - "busquedaSecuencial"
    clock_t inicio = clock();
    int resultado = busquedaSecuencial(array, N, elemento_a_buscar);
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Respuestas solución:
    if (resultado != -1) {
        printf("Elemento encontrado en el indice %d.\n", resultado);
    } else {
        printf("Elemento no encontrado.\n");
    }

    printf("Tiempo de ejecucion: %f segundos\n", tiempo);


    // Liberar la memoria del array
    free(array);

    return 0;
}


// Subprogramas:
int busquedaSecuencial(int *array, int tam, int elem) {
    for (int i = 0; i < tam; i++) {
        if (array[i] == elem) {
            return i; // Elemento encontrado, devuelve su índice
        }
    }
    return -1; // Elemento no encontrado, devuelve -1
}

int busquedaBinaria(int *array, int tam, int elem){

}