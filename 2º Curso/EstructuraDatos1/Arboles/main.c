#include <stdio.h>
#include "tArbol.h"

int main() {
    tArbol cronos, zeus, atenea, dedalo, poseidon, pegaso, teseo, hera, hefesto, ares, izq, der;
    crearArbolBinVacio(&cronos), crearArbolBinVacio(&zeus), crearArbolBinVacio(&atenea), crearArbolBinVacio(&dedalo), crearArbolBinVacio(&poseidon), crearArbolBinVacio(&pegaso), crearArbolBinVacio(&teseo), crearArbolBinVacio(&hera), crearArbolBinVacio(&hefesto), crearArbolBinVacio(&ares), crearArbolBinVacio(&izq), crearArbolBinVacio(&der);
    tDios diosCronos, diosZeus, diosAtenea, diosDedalo, diosPoseidon, diosPegaso, diosTeseo, diosHera, diosHefesto, diosAres;
    crearDios(&diosCronos, "Cronos", "dios del tiempo"), crearDios(&diosZeus, "Zeus", "dios supremo, líder de los 12 dioses olímpicos"), crearDios(&diosAtenea, "Atenea", "diosa de la civilización, la sabiduría, la razón, la inteligencia y la estrategia de combate"), crearDios(&diosDedalo, "Dedalo", " brillante inventor, técnico y arquitecto"), crearDios(&diosPoseidon, "Poseidon", " dios de los mares y de los terremotos"), crearDios(&diosPegaso, "Pegaso", "caballo alado, portador del rayo y del trueno"), crearDios(&diosTeseo, "Teseo", ": fundador de Atenas"), crearDios(&diosHera, "Hera", "diosa del matrimonio, las mujeres, el cielo y las estrellas"), crearDios(&diosHefesto, "Hefesto", " dios de la forja y del fuego, de los herreros, de los artesanos y los escultores"), crearDios(&diosAres, "Ares", "dios de la guerra, de la brutalidad y los horrores de las batallas");

// Construccion del arbol por jerarquías:
    construirArbolB(&dedalo, &izq, &der, diosDedalo), construirArbolB(&pegaso, &izq, &der, diosPegaso), construirArbolB(&teseo, &izq, &der, diosTeseo);
    construirArbolB(&atenea, &dedalo, &der, diosAtenea), construirArbolB(&poseidon, &pegaso, &teseo, diosPoseidon), construirArbolB(&hefesto, &izq, &der, diosHefesto), construirArbolB(&ares, &izq, &der, diosAres);
    construirArbolB(&zeus, &atenea, &poseidon, diosZeus), construirArbolB(&hera, &hefesto, &ares, diosHera);
    construirArbolB(&cronos, &zeus, &hera, diosCronos);

// Existe el dios en el arbol:
    existeDios(cronos, diosCronos);


    return 0;
}
