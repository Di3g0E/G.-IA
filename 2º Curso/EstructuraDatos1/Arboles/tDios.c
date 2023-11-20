//
// Created by Diego on 16/11/2023.
//

#include "tDios.h"

void asignar(tDios *info, tDios e){
    strcpy(info->nombre, e.nombre);
    strcpy(info->descripcion, e.descripcion);
}


void crearDios(tDios *d, char nom[N], char descr[M]){
    strcpy(d->nombre, nom);
    strcpy(d->descripcion, descr);
}