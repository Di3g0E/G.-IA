#include <math.h>

// Especificación COMPLEJOS

typedef struct {
    int re;
    int im;
} tComplejo;

// Operaciones constructoras generadoras:
tComplejo crearComplejo(int re, int im){
    tComplejo complejo;
    complejo.re = re;
    complejo.im = im;
    return complejo;
}

// Operaciones constructoras selectoras:
int obtenerReal(tComplejo complejo){
    return complejo.re;
}
int obtenerImaginario(tComplejo complejo){
    return complejo.im;
}

// Operaciones constructoras no selectoras:
float calcularModulo(tComplejo complejo){
    return sqrt(pow(complejo.re, 2) + pow(complejo.im, 2));
}

// Operaciones constructoras no generadoras:
tComplejo conjugado(tComplejo complejo){
    complejo.im = -complejo.im;
    return complejo;
}
tComplejo sumar(tComplejo complejo_UNO, tComplejo complejo_DOS){
    int re = complejo_UNO.re + complejo_DOS.re;
    int im = complejo_UNO.im + complejo_DOS.im;
    return crearComplejo(re, im);
}
tComplejo restar(tComplejo complejo_UNO, tComplejo complejo_DOS){
    int re = complejo_UNO.re - complejo_DOS.re;
    int im = complejo_UNO.im - complejo_DOS.im;
    return crearComplejo(re, im);
}
tComplejo multiplicar(tComplejo complejo_UNO, tComplejo complejo_DOS){
    int re = (complejo_UNO.re * complejo_DOS.re + complejo_UNO.im * complejo_DOS.im) / (pow(complejo_DOS.re, 2) + pow(complejo_DOS.im, 2));
    int im = (complejo_UNO.im * complejo_DOS.re - complejo_UNO.re * complejo_DOS.im) / (pow(complejo_DOS.re, 2) + pow(complejo_DOS.im, 2));
    return crearComplejo(re, im);
}
tComplejo dividir(tComplejo complejo_UNO, tComplejo complejo_DOS) {
    if (obtenerReal(complejo_DOS) != 0 && obtenerImaginario(complejo_DOS) != 0){
        int re = (complejo_UNO.re * complejo_DOS.re + complejo_UNO.im * complejo_DOS.im) / (pow(complejo_DOS.re, 2) + pow(complejo_DOS.im, 2));
        int im = (complejo_UNO.im * complejo_DOS.re - complejo_UNO.re * complejo_DOS.im) / (pow(complejo_DOS.re, 2) + pow(complejo_DOS.im, 2));
        return crearComplejo(re, im);
    }
}
tComplejo I(){
    return crearComplejo(0, 1);
}

// FIN ESPECIFICACIÓN COMPLEJOS

// ESPECIFICACIÓN ENTEROS

typedef struct {
    int num;
}tEntero;

// Operaciones constructoras generadoras:
tEntero CERO;
tEntero SUCESOR(int num){
    return num + 1;
}
tEntero PREDECESOR(int num){
    return num - 1;
}

// Operaciones constructoras selectoras:

// Operaciones constructoras no selectoras:

// Operaciones constructoras no generadoras:
tEntero sumarEntero(int num_UNO, int num_DOS){
    return num_UNO + num_DOS;
}
tEntero restarEntero(int num_UNO, int num_DOS){
    return num_UNO - num_DOS;
}
tEntero multiplicarEntero(int num_UNO, int num_DOS){
    return num_UNO * num_DOS;
}
tEntero dividirEntero(int num_UNO, int num_DOS) {
    return int(num_UNO / num_DOS);
}

// FIN ESPECIFICACIÓN ENTEROS