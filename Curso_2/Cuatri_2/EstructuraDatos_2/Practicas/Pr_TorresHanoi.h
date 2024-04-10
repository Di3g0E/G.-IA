//
// Created by Diego on 22/02/2024.
//

#ifndef PRACTICAS_PR_TORRESHANOI_H
#define PRACTICAS_PR_TORRESHANOI_H

#include <stack>

template <typename T>
class Torre {
public:
    template <typename S>
    class Disco {
        friend class Torre;

        auto getSize(S disc) {return disc.size;}
        auto getPos(S disc) {return disc.pos;}

        S id;       // Identificación
        S size;     // Tamaño del disco
    };

    auto moveDisc(Disco<T> disc) {}
private:
    // Crear tres torres como tres pilas en memoria dinámica
};

#endif //PRACTICAS_PR_TORRESHANOI_H
