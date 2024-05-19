//
// Created by Diego on 28/02/2024.
//

#ifndef PRACTICA_TABLA_HASH_TABLAHASH_H
#define PRACTICA_TABLA_HASH_TABLAHASH_H

#include <vector>
#include <list>
#include <iostream>
#include "Persona.h"

template <typename T, int N=100>
class efficientStorage {
public:

    /*
    void insert(const T& e){
        if (storage.size() < (N/2)){
            if (N >= 1000){
                storage[hash(e, 3)] = e;
            } else storage[hash(e)] = e;
        } else {std::cout<<"No caben mas elementos\n";}
    }*/ // Ejercicio 1

    void insert(const T& e){
        if (storage.size() < (N*0.75)){
            if (N >= 1000){
                if (storage[hash(e, 3)].size() != 0) {
                    ++cont;
                }
                storage[hash(e, 3)].push_front(e);
            } else { if (storage[hash(e, 3)].size() != 0) {
                    ++cont;
                }
                storage[hash(e)].push_front(e);
            }
        } else {std::cout<<"No caben mas elementos\n";}
    }

    void remove(const T& e){
        storage[hash(e)] = {};
    }

    bool contains(const T& e){
        return storage[hash(e)] == e;   // CORREGIR: recorrer la lista buscando el elemento 'e'
    }

    int tamanio(){return N;}

private:
    std::vector<std::list<T>> storage{N};
    int cont = 0;
};

#endif //PRACTICA_TABLA_HASH_TABLAHASH_H
