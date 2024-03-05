#include <iostream>
#include <mmcobj.h>
#include "ListaEnlazadaSimple.h"
#include "Pila.h"
#include "Cola.h"
#include "LinkedTree.h"

int main() {
    // ListaEnlazadaSimple:
    std::cout<<"Lista enlazada simple:\n";
    ListaEnlazadaSimple<int> l;

    l.add(1);
    l.add(2);
    l.add(3);

    l.imprimir();
    std::cout<<"El primer elemento de la lista es: "<<l.primero()<<'\n';
    l.borrar(3);
    l.resto();

    l.imprimir();

    // Pila:
    std::cout<<"\nPila:\n";
    Pila<int> p;

    p.add(1);
    p.add(2);

    std::cout<<"La cabeza de la pila es: "<<p.cabeza()<<'\n';
    p.resto();
    std::cout<<"La cabeza de la pila es: "<<p.cabeza()<<'\n';

    // Cola:
    std::cout<<"\nCola:\n";
    Cola<int> c;

    c.add(1);
    c.add(2);
    c.add(3);

    c.imprimir();
    std::cout<<"El primer elemento de la cola es: "<<c.primero()<<'\n';
    c.resto();
    c.imprimir();

    // LinkedTree:
    std::cout<<"\nLinkedTree:\n";
    LinkedTree<int> t;

    auto n1 = t.add(1);
    auto n2 = t.add(2, n1);
    auto n3 = t.add(3, n1);
    auto n4 = t.add(4, n2);

    t.gerRoot();
    t.getElement(n1);
    t.getParent(n2);
    t.getChildren(n4);

    t.isEmpty();
    t.isRoot(n1);
    t.isLeave(n4);
    t.isInternal(n4);

    t.cut(n4);
    t.concat(n4, n2);

    t.parentNotGrandparent(n2);
    t.parentNotGrandparent(n1);
    t.uncleWithoutChildren(n3);

    return 0;
}
