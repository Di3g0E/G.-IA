//
// Created by Diego on 05/04/2024.
//

#ifndef ESTUDIOPRACTICA_GRAFOS_H
#define ESTUDIOPRACTICA_GRAFOS_H

#include <iostream>
#include <unordered_map>

struct Book{
    std::string title;
    std::string author;
    int year;
    int npages;


    auto operator<=>(const Book& rhs) {
        return title <=> rhs.title;
    }

    void mostrar(){
        std::cout << "Titulo: " << title << "\t" << "Autor: " << author << "\t" << "Año: " << year << "\t" << "Num. paginas: " << npages << "\n";
    }
};

template <>
        class std::hash<Book> {
auto operator()(const Book& rhs) {
return std::hash<std::string>()(rhs.title);
}
};


#endif //ESTUDIOPRACTICA_GRAFOS_H
