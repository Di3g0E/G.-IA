#include <iostream>
//#include "ListaEnlazadaSimple.h"
#include "ListaEnlazadaSimple_sinDestructor.h"

int main() {
    ListaEnlazadaSimple_sinDestructor<int> l;
    l.insertar(3);
    l.insertar(2);
    l.insertar(4);
    l.insertar(3);

    l.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<l.primero()<<'\n';

    l.resto();

    l.imprimir();
    std::cout<<'\n';

    ListaEnlazadaSimple_sinDestructor<std::string> q;
    q.insertar("hola");
    q.insertar("adios");
    q.insertar("Paco");
    q.insertar("Juanillo");

    q.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<q.primero()<<'\n';

    q.resto();

    q.imprimir();



    return 0;
}
