#include <iostream>
#include "ListaEnlazadaSimple.h"
#include "EjPropuestosClase.h"
#include "LinkedTree.h"
#include "Tablas_Hash.h"
#include "ArbolBinarioBusqueda.h"
//#include "Iterador_pos_par.h"
//#include "Iterador_num_par.h"
//#include "Inorden_iterator.h"
#include "Grafos.h"
#include "Preorden_iterator.h"




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
*/  // Lista Enlazada Simple

    /*
    LinkedTree<int> t;
    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    auto root = t.add(42);
    auto n1 = t.add(37, root);
    auto n2 = t.add(3, root);
    auto n11 = t.add(17, n1);
    auto n21 = t.add(9, n2);
    auto n22 = t.add(27, n2);
    auto n23 = t.add(81, n2);

    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    std::cout << "¿Es root Root?: " << t.isRoot(root) << "\n";
    std::cout << "¿Es n1 Root?: " << t.isRoot(n1) << "\n";
    std::cout << "¿Es n11 Root?: " << t.isRoot(n11) << "\n";
    std::cout << "¿Es hoja root?: " << t.isLeaf(root) << "\n";
    std::cout << "¿Es hoja n2?: " << t.isLeaf(n2) << "\n";
    std::cout << "¿Es hoja n22?: " << t.isLeaf(n22) << "\n";
    std::cout << "¿Es interno Root?: " << t.isInternal(root) << "\n";
    std::cout << "¿Es interno n23?: " << t.isInternal(n23) << "\n";
    std::cout << "¿Es root el padre de n1?: " << (root == t.getParent(n1)) << "\n";
    std::cout << "¿Es root el padre de n11?: " << (root == t.getParent(n11)) << "\n";
    std::cout << "¿Es n2 el padre de n21?: " << (n2 == t.getParent(n21)) << "\n";
    std::cout << "¿Es n2 el padre de n11?: " << (n2 == t.getParent(n11)) << "\n";*/  //  LinkedTree

    /*
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16};
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16};
    std::forward_list<int> f = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16};

    EvenPosIterable vectorEvenPosIterable(v);
    for (int i : vectorEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    EvenPosIterable listEvenPosIterable(l);
    for (int i : listEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    EvenPosIterable forwardEvenPosIterable(f);
    for (int i : forwardEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';
     */ // Iteradores


    Book libro1 {"T_1", "A_1", 1000, 100};
    Book libro2 {"T_2", "A_2", 2000, 200};
    Book libro3 {"T_3", "A_3", 3000, 300};
    Book libro4 {"T_4", "A_4", 4000, 400};

    std::unordered_map<Book, int> map;

    map[libro1] = 65;
    map[libro2] = 97;
    map[libro3] = 20;
    map[libro4] = 13;

    for (const auto& [key, value]: map){
        std::cout << "map[" << key.title << "] = " << value << "\n";
    }

    map.erase(libro4);

    std::cout << "********************************************\n";

    for (const auto& [key, value]: map){
        std::cout << "map[" << key.title << "] = " << value << "\n";
    }

    return 0;
}
