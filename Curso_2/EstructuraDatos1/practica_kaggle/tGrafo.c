//
// Created by Diego on 12/12/2023.
//

#include "tGrafo.h"

void crearArbolVacio(tArbol * a){
    *a = NULL;
}

void aniadirNodo(tArbol *a, tCompet c) {
    if (esVacio(*a)) {
        *a = (tArbol)malloc(sizeof(tNodo));
        asignar(&((*a)->info), c);
        (*a)->izq = NULL;
        (*a)->der = NULL;
    } else {
        if (c.premio < (*a)->info.premio) {
            aniadirNodo(&((*a)->izq), c);
        } else {
            aniadirNodo(&((*a)->der), c);
        }
    }
}


void eliminarNodo(tArbol *a, int premio) {
    if (esVacio(*a)) {
        return;
    }

    if (premio < (*a)->info.premio) {
        eliminarNodo(&((*a)->izq), premio);
    } else if (premio > (*a)->info.premio) {
        eliminarNodo(&((*a)->der), premio);
    } else {
        // Nodo encontrado, procedemos a la eliminación
        tNodo *temp = *a;

        // Caso 1: Nodo sin hijos o con un solo hijo
        if ((*a)->izq == NULL) {
            *a = (*a)->der;
        } else if ((*a)->der == NULL) {
            *a = (*a)->izq;
        } else {
            // Caso 2: Nodo con dos hijos
            // Encontramos el sucesor inmediato en el subárbol derecho
            tNodo *sucesor = (*a)->der;
            while (sucesor->izq != NULL) {
                sucesor = sucesor->izq;
            }

            // Copiamos la información del sucesor al nodo actual
            asignar(&((*a)->info), sucesor->info);

            // Eliminamos el sucesor
            eliminarNodo(&((*a)->der), sucesor->info.premio);
        }

        free(temp); // Liberamos el nodo eliminado
    }
}


void imprimir(tArbol a){
    int flag = 1;
    while (a != NULL && flag){
        imprimir((*a).izq);
        mostrarInfo((*a).info);
        imprimir((*a).der);
        flag = 0;
    }
}


void peorPremio(tArbol a){
    tNodo *aux = a;
    while (aux->izq != NULL){
        aux = aux->izq;
    }
    mostrarInfo(aux->info);
}


int esVacio(tArbol a){
    return (a == NULL);
}