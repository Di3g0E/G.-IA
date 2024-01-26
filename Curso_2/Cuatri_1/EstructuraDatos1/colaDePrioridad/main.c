#include <stdio.h>
#include "tHospital.h"

int main() {
    tHospital hospital;
    tElem paciente1 = {2, "Juan", 20, "Dolor de barriga"}, paciente2 = {2, "Pepe", 33, "Dolor de barriga"}, paciente3 = {4, "Pedro", 45, "Dolor de barriga"}, paciente0 = {1, "Tintin", 14, "Dolor de barriga"};

    crearHospitalVacio(&hospital, 75);
    insertarEnHospital(&hospital, paciente1);
    insertarEnHospital(&hospital, paciente2);
    insertarEnHospital(&hospital, paciente3);
    insertarEnHospital(&hospital, paciente0);

    quitarPrimero(&hospital);

    consultarPrimero(hospital);

    return 0;
}
