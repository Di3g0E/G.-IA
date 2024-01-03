//
// Created by Diego on 03/01/2024.
//

#include "tTweet.h"
#include <string.h>

void nombrarTweet(tTweet t1, tTweet t2){
    strcpy(t1, t2);
}


int mismoTweet(tTweet t1, tTweet t2){
    return strcmp(t1, t2);
}