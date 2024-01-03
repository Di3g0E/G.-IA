#include "tArbolBin.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100

int main() {
    FILE *file;
    char hashtag[MAX_CHAR];

    tArbol arbol;
    crearArbolVacio(&arbol);

    file = fopen("hashtags.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo.\n");
        return 1;
    }

    while (fgets(hashtag, MAX_CHAR, file) != NULL) {
        // Eliminar el salto de línea del hashtag leído
        size_t len = strlen(hashtag);
        if (len > 0 && hashtag[len - 1] == '\n') {
            hashtag[len - 1] = '\0';
        }

        tHashtag nuevoHashtag;
        nombrarHashtag(nuevoHashtag, hashtag);

        construirArbol(&arbol, nuevoHashtag);
    }

    fclose(file);

    // Ahora arbol contiene la información de los hashtags del archivo

    // Ejemplo de cómo etiquetar un tweet
    tTweet tweetEjemplo;
    // Inicializar el tweet de alguna manera
    etiquetarTweets(&arbol, arbol->hashtag, tweetEjemplo);

    // Ejemplo de cómo realizar una consulta
    tHashtag hashtagConsulta;
    // Inicializar el hashtag de alguna manera
    consultas(arbol, hashtagConsulta);

    return 0;
}