//
// Created by Diego on 16/11/2023.
//

#include "tDios.h"

void asignar(tDios *info, tDios e){
    strcpy(info->nombre, e.nombre);
    strcpy(info->descripcion, e.descripcion);
}


void crearDios(tDios *d, char* nom, char* descr){
    strcpy(d->nombre, nom);
    strcpy(d->descripcion, descr);
}


void mostrarDios(tDios d){
    printf(d.nombre);
}


int mismoDios(tDios a, tDios b){
    return strcmp(a.nombre, b.nombre);
}