//
// Created by Diego on 04/03/2024.
//

#ifndef REPASOCOMPLETO_PILA_H
#define REPASOCOMPLETO_PILA_H

#include <memory>
#include <iostream>

template <typename T>
class Pila{
public:
    template <typename S>
    class Node{
        friend class Pila;
        S info;
        std::shared_ptr<Node<S>> sig;
    };

    void add(T e){
        auto node = std::make_shared<Node<T>>();
        node->info = e;
        node->sig = pila;
        pila = node;
    }

    T cabeza(){
        if (pila){
            return pila->info;
        }
        return T{};
    }

    void resto(){
        if (pila){
            pila = pila->sig;
        } else {std::cout<<"Pila vacia.\n";}
    }

private:
    std::shared_ptr<Node<T>> pila;
};

#endif //REPASOCOMPLETO_PILA_H
