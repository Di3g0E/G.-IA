#include <vector>
#include <iostream>
#include "TablaHash.h"
#include "Persona.h"


int main() {
    Persona p {"Diego", "Esclarin", 51769212, 'C'};

    efficientStorage<Persona>(l);

    l.insert(p);
    std::cout<<l.contains(p)<<'\n';
    l.remove(p);
    std::cout<<l.contains(p)<<'\n';
    std::cout<<l.tamanio()<<'\n';



    return 0;
}
