#include <iostream>
#include "ListaEnlazadaSimple.h"
#include "EjPropuestosClase.h"
#include "LinkedTree.h"
#include "Tablas_Hash.h"
#include "ArbolBinarioBusqueda.h"

int main() {
    /*
    ListaEnlazadaSimple<int> l;
    l.insertar(3);
    l.insertar(2);
    l.insertar(4);
    l.insertar(3);

    l.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<l.primero()<<'\n';

    l.resto();

    l.imprimir();
    std::cout<<'\n';

    ListaEnlazadaSimple<std::string> q;
    q.insertar("hola");
    q.insertar("adios");
    q.insertar("Paco");
    q.insertar("Juanillo");

    q.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<q.primero()<<'\n';

    q.resto();

    q.imprimir();
*/

    /*
     * Myclass<std::string> c;
    Printer p;

    c[3] = "tres";
    c[42] = "cuarenta y dos";

    std::cout<<"c[3] = "<<c[3]<<'\n';

    p.print("cuarenta y dos", 42);
     */

    HashMapEs<int, int> mymap;

    mymap[3] = 42;

    if (mymap.contains(37)){
        std::cout<<"Yes"<<'\n';
    }else std::cout<<"No"<<'\n';

    if (mymap.contains(3)){
        std::cout<<"Yes"<<'\n';
    }else std::cout<<"No"<<'\n';

    return 0;
}
