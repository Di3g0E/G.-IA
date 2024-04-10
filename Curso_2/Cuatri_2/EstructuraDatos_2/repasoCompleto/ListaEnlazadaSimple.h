//
// Created by Diego on 04/03/2024.
//

#ifndef REPASOCOMPLETO_LISTAENLAZADA_H
#define REPASOCOMPLETO_LISTAENLAZADA_H

#include <memory>
#include <iostream>

template <typename T>
class ListaEnlazadaSimple {
public:
    template <typename S>
    class Node{
        friend class ListaEnlazadaSimple;
        S info;
        std::shared_ptr<Node<S>> sig = nullptr;
    };

    ~ListaEnlazadaSimple(){
        while (lista){
            resto();
        }
    }

    T primero(){
        if (lista){
            return lista->info;
        }
        return T{};
    }

    void resto(){lista = lista->sig;}

    T getInfo(const Node<T>& e){return e.info;}

    void add(T e){
        auto nodo = std::make_shared<Node<T>>();
        nodo->info = e;
        nodo->sig = lista;
        lista = nodo;
    }

    void borrar(T e){
        auto aux = lista;
        auto ant = lista;
        while (aux->info != e && aux != nullptr){
            ant = aux;
            aux = aux->sig;
        }
        if (aux != nullptr){
            ant->sig = aux->sig;
        }
    }

    void imprimir(){
        if (lista){
            auto aux = lista;
            while (aux) {
                std::cout << aux->info << ' ';
                aux = aux->sig;
            }
        } else {std::cout<<"La lista esta vacia.\n";}
        std::cout<<'\n';
    }

private:
    std::shared_ptr<Node<T>> lista;
};

#endif //REPASOCOMPLETO_LISTAENLAZADA_H
