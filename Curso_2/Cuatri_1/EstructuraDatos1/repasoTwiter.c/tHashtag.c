//
// Created by Diego on 03/01/2024.
//

#include "tHashtag.h"
#include <string.h>

void nombrarHashtag(tHashtag h1, tHashtag h2){
    strcpy(h1, h2);
}


int mismoHashtag(tHashtag h1, tHashtag h2){
    return strcmp(h1, h2);
}