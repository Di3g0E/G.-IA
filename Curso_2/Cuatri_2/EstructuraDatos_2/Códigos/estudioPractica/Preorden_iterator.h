//
// Created by Diego on 10/04/2024.
//

#ifndef ESTUDIOPRACTICA_PREORDEN_ITERATOR_H
#define ESTUDIOPRACTICA_PREORDEN_ITERATOR_H

#include <stack>

template <typename T>
class Preorder_iterator {
public:
    Preorder_iterator(t) : t(t), it(t.getRoot()) {   //constructor
        p.push(t.getRoot());

    }

    Preorder_iterator& operator++(){
        //se guarda lo que hay en la cima
        auto c = p.top();
        //quita lo que hay en la pila
        p.pop();
        //sacar el hijo izq e insertarlo idem con el derecho
        auto node = t.getRightChild(c);
        if (node) p.push(p);
        auto node = t.getLeftChild(c);
        if (node) p.push(p);
        return *this;

    }

    auto operator*() {
        return t.getElement(p.top()); //*it;
    }

    bool operator !=(const Even_value_iterator& other) { //indireccion muestra cima pila (expansión)
        return p != other.p;
    }
    //inorder=> trasverseLeft: todos los hijos izquierdos de la raiz
    //postorder =>

private:
    T t;
    std::stack<T::Node*> p;//dentro de la libreria si no se ha definido antes
    };
}

#endif //ESTUDIOPRACTICA_PREORDEN_ITERATOR_H
