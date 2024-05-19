//
// Created by Diego on 02/02/2024.
//

#ifndef ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_SINDESTRUCTOR_H
#define ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_SINDESTRUCTOR_H

#include <memory>

template <typename T>
struct Nodo{
    T dato;
    std::shared_ptr<Nodo<T>> sig;
};

// Es una pila
template <typename T>
class ListaEnlazadaSimple_sinDestructor{
public:
    void insertar(T x){
        auto nodo = std::make_shared<Nodo<T>>(x, l);
        l = nodo;
    }

    T primero(){
        if (l) {
            return l->dato;
        }
        return T{};
    }

    void resto(){
        if (l) {
            l = l->sig;
        }
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
    std::shared_ptr<Nodo<T>> l = nullptr;
};  // Es una pila

#endif //ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_SINDESTRUCTOR_H
