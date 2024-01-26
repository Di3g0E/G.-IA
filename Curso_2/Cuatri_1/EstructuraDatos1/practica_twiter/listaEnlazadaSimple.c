//
// Created by Diego on 24/10/2023.
//

#include "listaEnlazadaSimple.h"
#include <stdio.h>
#include <stdlib.h>

void crearVacia(tLista* lista){
    *lista = NULL;
}


void insertarCabecera(tLista* lista, tElem elem){
    tNodo* aux = (tNodo*) malloc(1 * sizeof (tNodo));
    asignar(&aux->elem, elem);
    aux->sig = *lista;
    *lista = aux;
}


void insertarFinal(tLista* lista, tElem elem){
    tNodo* new = (tNodo*) malloc(1* sizeof (tNodo));        // Reservo espacio en mem. dinámica para el nodo a añadir
    if (*lista == NULL){                                    // Si la lista está vacía se modifican los punteros
        new->sig = NULL;
        *lista = new;
        asignar(&new->elem, elem);                          // Le asigno la información del elemento al nuevo nodo
    } else{
        tNodo* aux = *lista;                                // Creo una variable que recorra la lista hasta la última posición
        while (aux->sig != NULL){                           // Mientras la siguiente posición no sea NULL sigue avanzando
            aux = aux->sig;
        }
        asignar(&new->elem, elem);                          // Le asigno la información del elemento al nuevo nodo
        new->sig = aux->sig;                                // Le asigno la siguiente posición del antiguo último nodo al nuevo nodo
        aux->sig = new;                                     // Le paso la dirección de memoria del nuevo nodo al nodo anterior
    }
}


void eliminarElemento(tLista* lista, tElem elem){
    tNodo* aux = *lista;
    tNodo* ant = NULL;
    int encontrado = 0;                                         // 0 indica True

    while (encontrado == 0 && aux->sig != NULL){
        encontrado = igualTituloElemento(aux->elem, elem);
        if (encontrado == 1){
            ant = aux;
            aux = aux->sig;
            encontrado = 0;
        }
        else {
            if (ant == NULL){
                *lista = aux->sig;
            } else{
                ant->sig = aux->sig;
            }
            free(aux);
            encontrado = 1;
        }
    }
}


void mostrarLista(tLista *lista){
    tNodo *aux = *lista;
    while (aux != NULL){
        mostrarElemento(aux->elem);
        aux = aux->sig;
    }
}


void obtenerPrimero(tLista lista, tElem *elem){
    asignar(elem, lista->elem);
}


void obtenerResto(tLista* lista, tLista* resto){
    tNodo *aux = *lista;
    *resto = (aux->sig);
}


void esListaVacia(tLista* lista){
    if (*lista == NULL){printf("\nLa lista esta vacia.\n");}
    else{printf("\nLa lista no esta vacia.\n");}
}


int longitud(tLista* lista){
    tNodo *aux = *lista;
    int cont = 0;
    while (aux->sig != NULL){
        aux = aux->sig;
        cont++;
    }
    return cont;
}


void concatenar(tLista* lista1, tLista* lista2){
    tNodo *aux = *lista1;
    while (aux->sig != NULL){
        aux = aux->sig;
    }
    aux->sig = *lista2;
}


int contieneElem(tLista* lista, tElem elem){
    tNodo *aux = *lista;
    int flag;
    flag = igualTituloElemento(aux->elem, elem);
    while (flag == 1){
        aux = aux->sig;
        flag = igualTituloElemento(aux->elem, elem);
    }
    return flag;
}
