//
// Created by Diego on 07/11/2023.
//

#include "tPaciente.h"

void asignarInfo(tElem paciente_ini, tElem* paciente_dest){
    paciente_dest->exp = paciente_ini.exp;
    strcpy(paciente_dest->nombre, paciente_ini.nombre);
    paciente_dest->edad = paciente_ini.edad;
    strcpy(paciente_dest->dolecia, paciente_ini.dolecia);
}


void mostrarPaciente(tElem paciente){
    printf("La prioridad del paciente es: %d\t", paciente.exp);
    printf("\tNombre: %s\t\tEdad: %d\t", paciente.nombre, paciente.edad);
    printf("Dolencia: %s\n", paciente.dolecia);
}