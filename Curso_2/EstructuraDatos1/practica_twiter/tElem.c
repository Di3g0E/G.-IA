//
// Created by Diego on 14/12/2023.
//

#include "tElem.h"
#include <string.h>

void asignar(tElem * dest, tElem orig){
    strcpy(&dest->hashtag, &orig.hashtag);
    dest->tweets = orig.tweets;
}