//
// Created by Diego on 03/02/2024.
//

#ifndef ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
#define ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H

#include <memory>

template <typename T>
class ListaEnlazadaSimple{
public:
    template <typename S>
    class Node {
        friend class ListaEnlazadaSimple;
        S info;
        std::shared_ptr<Node<S>> sig;
    };

    void insertar(T e) {
        auto nodo = std::make_shared<Node<T>>();
        nodo->info = e;
        nodo->sig = l;
        l = nodo;
    }

    void resto() {
        l = l->sig;
    }

    T primero() {
        if (l) {
            return l->info;
        }
        return T{};
    }

    void imprimir() {
        if (l) {
            auto aux = l;
            while (aux != nullptr) {
                std::cout<<aux->info<<' ';
                aux = aux->sig;
            }
        } else { std::cout << "La lista esta vacia.\n"; }
    }

private:
    std::shared_ptr<Node<T>> l;
};

#endif //ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_H
