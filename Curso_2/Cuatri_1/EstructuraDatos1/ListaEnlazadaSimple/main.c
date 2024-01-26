#include <stdio.h>
#include <stdlib.h>
#include "listaEnlazadaSimple.h"

int main() {
    // Crear una lista enlazada de tNodo
    tLista lista, lista1;
    crearVacia(&lista);
    crearVacia(&lista1);

    // Crear elementos y agregarlos a la lista
    tElem elemento1 = { "Articulo 1", { 1, 1, 2023 }, "Fuente 1", 100 };
    insertarCabecera(&lista, elemento1);

    tElem elemento2 = { "Articulo 2", {2, 1, 2023}, "Fuente 2", 200 };
    insertarCabecera(&lista, elemento2);

    tElem elemento3 = { "Articulo 3", {3, 1, 2023}, "Fuente 3", 300 };
    insertarCabecera(&lista, elemento3);

    tElem elemento4 = { "Articulo 4", {4, 1, 2023}, "Fuente 4", 400 };
    insertarCabecera(&lista, elemento4);

    tElem elemento5 = { "Articulo 5", {5, 1, 2023}, "Fuente 5", 500 };
    insertarCabecera(&lista, elemento5);

    tElem elemento6 = { "Articulo 6", {6, 1, 2023}, "Fuente 6", 600 };
    insertarFinal(&lista, elemento6);

    tElem elemento7 = { "Articulo 7", {7, 1, 2023}, "Fuente 7", 700 };
    insertarFinal(&lista1, elemento7);

    // Eliminar un nodo de la lista
    eliminarElemento(&lista, elemento3);

    // Obtener primero
    tElem elem_1;
    obtenerPrimero(lista, &elem_1);
    printf("El primer elemento de la lista es: ");
    mostrarElemento(elem_1);

    // Obtener resto
    tLista resto;
    crearVacia(&resto);
    obtenerResto(&lista, &resto);
    printf("\nEl resto de la lista es:\n");
    mostrarLista(&resto);

    // Imprimir la lista actualizada
    printf("\nLa lista 'lista' contiene:\n");
    mostrarLista(&lista);

    printf("\nLa lista 'lista1' contiene:\n");
    mostrarLista(&lista1);

    // Indicar si la lista está vacía o no
    esListaVacia(&lista);

    // Indicar la longitud de la lista
    int num_nodos;
    num_nodos = longitud(&lista);
    printf("\nLa longitud de la lista es de %d elementos.\n", num_nodos);

    // Concatenar dos listas
    printf("\nLa concatenacion de las listas es:\n");
    concatenar(&lista, &lista1);
    //concatenar(&lista, &resto);              ¿Por qué me da un bucle?
    mostrarLista(&lista);

    // ¿La lista contiene el elemento?
    int solucion;
    solucion = contieneElem(&lista, elemento7);
    if (solucion == 0) {printf("\nLa lista si contiene el elemento '%s'.\n", &elemento7.titulo);}
    else { printf("\nLa lista no contiene el elemento '%s'.\n", &elemento7.titulo);}


    return 0;
}
