//
// Created by Diego on 19/10/2023.
//

#include "tElem.h"

void asignar(tElem* nodo, tElem e){
    strcpy(nodo->titulo, e.titulo);
    nodo->fecha = e.fecha;
    strcpy(nodo->fuente, e.fuente);
    nodo->visitas = e.visitas;
}


int igualTituloElemento(tElem e1, tElem e2){    // 0 indica iguales, 1 desiguales
    int aux;

    if (strcmp(e1.titulo, e2.titulo) == 0){
        aux = 0;
    } else aux = 1;

    return aux;
}


void mostrarElemento(tElem elem){
    printf("Titulo: %s\t", elem.titulo);
    printf("Fecha: %d-%d-%d\t\t", elem.fecha.dia, elem.fecha.mes, elem.fecha.anio);
    printf("Fuente: %s\t", elem.fuente);
    printf("Visitas: %d\n", elem.visitas);
}
