//
// Created by Diego on 01/02/2024.
//

#ifndef ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
#define ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H

#include "Elemento.h"

template <typename T>
struct Nodo{
    T dato;
    Nodo<T> * sig;
};

template <typename T>
class ListaEnlazadaSimple{
public:
    ~ListaEnlazadaSimple(){
        if (l){
            resto();
        }
    }

    void insertar(auto x){
        auto aux = new Nodo<T>{x, l};
        l = aux;
    }

    void primero(auto x){
        x = l->dato;
    }

    void resto(){
        if (l) {
            auto aux = l;
            l = l->sig;
            delete aux;
        }
    }

    void mostrarPrimero(){
        std::cout<<"El primer elemento de la lista es: "<< l->dato << "\n";
    }

    void imprimir(){
        auto aux = l;
        while (aux != nullptr) {
            std::cout<<aux->dato<<' ';
            aux = aux->sig;
        }
        std::cout<<'\n';
    }


private:
    Nodo<T> * l = nullptr;
};

#endif //ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
