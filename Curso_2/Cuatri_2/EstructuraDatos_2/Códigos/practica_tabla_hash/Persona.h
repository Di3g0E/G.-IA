//
// Created by Diego on 28/02/2024.
//

#ifndef PRACTICA_TABLA_HASH_PERSONA_H
#define PRACTICA_TABLA_HASH_PERSONA_H

#include <vector>
#include <iostream>

struct Persona {
    std::string nombre;
    std::string apellidos;
    unsigned long long num_DNI;
    char letra_DNI;

    bool operator==(const Persona& rhs) const {
        return (nombre == rhs.nombre) && (apellidos == rhs.apellidos)
               && (num_DNI == rhs.num_DNI) && (letra_DNI == rhs.letra_DNI);
    }
};

int hash(Persona p, const int N = 100) {    // N indica el número de decimales que quieres usar para calcular la clave
    return p.num_DNI % N;
}

#endif //PRACTICA_TABLA_HASH_PERSONA_H
