#include <stdio.h>
#include "tArbol.h"

int main() {

    // PRUEBAS IMPLEMENTACIÓN ÁRBOLES
    tArbol a, b, izq, der;
    tElem e, r;
    tLista l;
    
    crearArbolVacio(&a);
    crearArbolVacio(&izq);
    crearArbolVacio(&der);

    construirArbol(&b,  izq, 5,  der);
    construirArbol(&a,  b, 2,  der);
    construirArbol(&b,  izq, 4,  a);
    construirArbol(&a,  b, 1,  a);                          // ((Na, 4, ((Na, 5, Na), 2, Na)), 1, ((Na, 5, Na), 2, Na))

    mostrarArbolPreorden(a); printf("\n");                  // Muestra el árbol por terminal de forma preorder (1 4 2 5 2 5)
    mostrarArbolInorden(a); printf("\n");                   // Muestra el árbol por terminal de forma inorder (4 5 2 1 5 2)
    mostrarArbolPostorden(a); printf("\n");                 // Muestra el árbol por terminal de forma postorder (5 2 4 5 2 1)

    printf("\nLa altura del arbol 'a' es:"); mostrarElem(altura(a));                                        // Devuelve la altura del árbol "a"
    printf("\n\nEl numero de nodos del arbol 'a' es:"); mostrarElem(numNodos(a)); printf("\n");             // Devuelve el número de nodos del árbol "a"

    if (esEquilibrado(a)) {                                 // Indica si el árbol "a" es equilibrado o no
        printf("\nEl arbol 'a' SI esta equilibrado");
    } else {printf("\nEl arbol 'a' NO esta equilibrado");} printf("\n");

    if (esHoja(b)) {                                        // Indica si "b" es una hoja o no
        printf("\nEl arbol 'b' SI es hoja");
    } else {printf("\nEl arbol 'b' NO es hoja");} printf("\n");

    printf("\nEl nivel de la raiz 1 es %d\n", nivel(a, 1)); // Indica el nivel del nodo con raíz valor 1

    return 0;
}
