//
// Created by Diego on 01/02/2024.
//

#ifndef ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_C_H
#define ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_C_H

template <typename T>
struct NodoC{
    T dato;
    NodoC<T> * sig;
};

// Es una pila
template <typename T>
class ListaEnlazadaSimple_C{
public:
    ~ListaEnlazadaSimple_C(){
        if (l){
            resto();
        }
    }

    void insertar(T x){
        auto aux = new NodoC<T>{x, l};
        l = aux;
    }

    T primero(){
        if (l) {
            return l->dato;
        }
        return T{};
    }

    void resto(){
        if (l) {
            auto aux = l;
            l = l->sig;
            delete aux;
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
    NodoC<T> * l = nullptr;
};  // Es una pila

#endif //ESTUDIOPRACTICA_LISTAENLAZADASIMPLE_C_H
