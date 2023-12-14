//
// Created by Diego on 24/10/2023.
//

#ifndef LISTAS_LISTAENLAZADASIMPLE_H
#define LISTAS_LISTAENLAZADASIMPLE_H

#include "tElem.h"


typedef struct Nodo{
    tElem elem;
    struct Nodo* sig;
} tNodo;

typedef tNodo* tLista;

void crearVacia(tLista* lista);
void insertarCabecera(tLista* lista, tElem elem);
void insertarFinal(tLista* lista, tElem elem);
void eliminarElemento(tLista* lista, tElem elem);
void mostrarLista(tLista *lista);
void obtenerPrimero(tLista lista, tElem* elem);
void obtenerResto(tLista* lista, tLista* resto);
void esListaVacia(tLista* lista);
int longitud(tLista* lista);
void concatenar(tLista* lista1, tLista* lista2);
int contieneElem(tLista* lista, tElem elem);

#endif //LISTAS_LISTAENLAZADASIMPLE_H
