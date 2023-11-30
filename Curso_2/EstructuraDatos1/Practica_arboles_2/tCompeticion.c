//
// Created by Diego on 28/11/2023.
//

#include "tCompeticion.h"

void asignar(tCompeticion * dest, tCompeticion orig){
    strcpy(dest->titulo, orig.titulo);
    dest->tiempo = orig.tiempo;
    dest->premio = orig.premio;
}