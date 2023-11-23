//
// Created by Diego on 07/11/2023.
//

#include "tHospital.h"

void crearHospitalVacio(tHospital* hospital, int camas_disponibles){
    hospital->numCamas = camas_disponibles;
    hospital->ini = NULL;
    hospital->fin = NULL;
}


void insertarEnHospital(tHospital* hospital, tElem paciente){
    if (hospital->numCamas > 0){

        tNodo* nodo = (tNodo*) malloc(sizeof (tNodo));
        asignarInfo(paciente, &nodo->info);
        if (esHospitalVacio(*hospital)){
            nodo->sig = hospital->fin;
            nodo->ant = hospital->ini;
            hospital->fin = nodo;
            hospital->ini = nodo;
        } else {
            tNodo* aux = hospital->fin;
            while (aux->ant != NULL && nodo->info.exp < aux->info.exp){
                aux = aux->ant;
            }
            if (aux->ant == NULL && nodo->info.exp < aux->info.exp) {
                // Insertar al principio
                nodo->ant = aux->ant;
                nodo->sig = aux;
                hospital->ini = nodo;
            } else {
                // Insertar en medio
                nodo->ant = aux;
                nodo->sig = aux->sig;
                aux->sig = nodo;
                if (nodo->sig == NULL){
                    hospital->fin = nodo;
                }
            }
        }
        hospital->numCamas --;
    } else { printf("No hay mas camas disponibles.\n");}
}


void consultarPrimero(tHospital hospital){
    if (!esHospitalVacio(hospital)){
        tNodo aux = *hospital.ini;
        mostrarPaciente(aux.info);
    } else { printf("El hospital esta vacio.\n");}
}


void quitarPrimero(tHospital* hospital){
    if (!esHospitalVacio(*hospital)){
        tNodo * aux = hospital->ini;
        hospital->ini = aux->sig;
        free(aux);
    } else { printf("El hospital esta vacio.\n");}
}


int esHospitalVacio(tHospital hospital){
    return hospital.ini == NULL && hospital.fin == NULL;
}