//
// Created by Diego on 04/03/2024.
//

#ifndef REPASOCOMPLETO_COLA_H
#define REPASOCOMPLETO_COLA_H

#include <memory>
#include <iostream>

template <typename T>
class Cola{
public:
    template <typename S>
    class Node{
        friend class Cola;
        S info;
        std::shared_ptr<Node<S>> ant = nullptr;
        std::shared_ptr<Node<S>> sig = nullptr;
    };

    void add(T e){
        auto nodo = std::make_shared<Node<T>>();
        nodo->info = e;
        nodo->ant = cola;
        if (cabeza){
            cabeza->sig = nodo;
        } else {cabeza = nodo;}
        cola = nodo;
    }

    T primero(){
        if (cabeza) {
            return cabeza->info;
        }
        return T{};
    }

    void resto(){
        auto aux = cabeza->sig;
        cabeza = cabeza->sig;
        aux->ant = nullptr;
    }

    void imprimir(){
        if (cabeza){
            auto aux = cabeza;
            while (aux){
                std::cout<<aux->info<<' ';
                aux = aux->sig;
            }
            std::cout<<'\n';
        } else std::cout<<"La cola está vacia\n";
    }


private:
    std::shared_ptr<Node<T>> cabeza = nullptr;
    std::shared_ptr<Node<T>> cola = nullptr;
};

#endif //REPASOCOMPLETO_COLA_H
