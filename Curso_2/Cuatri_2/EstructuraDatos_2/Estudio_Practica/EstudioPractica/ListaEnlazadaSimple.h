//
// Created by Diego on 01/02/2024.
//

#ifndef ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
#define ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H

#include "Elemento.h"

struct Nodo{
    tElem info;
    Nodo * sig;
};

class ListaEnlazadaSimple{
public:
    ~ListaEnlazadaSimple(){
        if (l){
            resto();
        }
    }

    void insertar(int x){
        auto aux = new Nodo{x, l};
        l = aux;
    }

    void primero(auto x){
        x = l->info;
    }

    void resto(){
        if (l) {
            auto aux = l;
            l = l->sig;
            delete aux;
        }
    }

    void mostrarPrimero(){
        std::cout<<"El primer elemento de la lista es: "<< l->info << "\n";
    }

    void imprimir(){
        auto aux = l;
        while (aux != nullptr) {
            std::cout<<aux->info<<' ';
            aux = aux->sig;
        }
        std::cout<<'\n';
    }


private:
    Nodo * l = nullptr;
};

#endif //ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
