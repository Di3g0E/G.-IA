//
// Created by Diego on 06/03/2024.
//

#ifndef ESTUDIOPRACTICA_TABLAS_HASH_H
#define ESTUDIOPRACTICA_TABLAS_HASH_H

#include <iostream>
#include <vector>

auto hash(int num){
    return num%100;
}

template <typename KeyType, typename ValueType, int size = 100>
class HashMapEs{
public:
    ValueType operator[](KeyType k) const {
        auto idx = compress(std::hash(k));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            if (!encontrado) ++it;
        }
        if (encontrado) {return (*it).second;} else return ValueType{};
    }

    ValueType& operator[](KeyType k) {
        auto idx = compress(std::hash(k));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            if (!encontrado) ++it;
        }
        if (encontrado) {return (*it).second;} else {
            m[idx].push_front(std::make_pair(k, ValueType{}));
            return m[idx].front().second;
        };
    }

    bool contains(KeyType k){
        auto idx = compress(std::hash(k));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            ++it;
        }
        return encontrado;
    }

private:
    std::vector<std::list<std::pair<KeyType, ValueType>>> m{size};
    size_t compress(KeyType k){return k % size;}
};

template <typename KeyType, typename ValueType, int size = 100>
class HashMapLP{
public:
    ValueType operator[](KeyType k) const {
        int p = 0;
        auto idx = compress(std::hash(k, p));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            if (!encontrado) ++it;
        }
        if (encontrado) {return (*it).second;} else return ValueType{};
    }

    ValueType& operator[](KeyType k) {
        int p = 0;
        auto idx = compress(std::hash(k, p));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            if (!encontrado) ++it;
        }
        if (encontrado) {return (*it).second;} else {
            m[idx].push_front(std::make_pair(k, ValueType{}));
            return m[idx].front().second;
        };
    }

    bool contains(KeyType k){
        int p = 0;
        auto idx = compress(std::hash(k, p));
        bool encontrado = false;
        auto it = m[idx].begin();

        while ((!encontrado) && (it != m[idx].end())){
            encontrado = (*it).first == k;
            ++it;
        }
        return encontrado;
    }

private:
    std::vector<std::tuple<KeyType, ValueType, bool>> m{size};;
    int hash(KeyType k, int p = 0){return std::hash<KeyType>(k) + p;}
    size_t compress(KeyType k){return k % size;}
};

/*class Printer {
public:
    void print(HashMap<std::string>& c, int idx) const {
    std::cout<<"c["<<idx<<"] = "<<c[idx]<<'\n';
};*/


#endif //ESTUDIOPRACTICA_TABLAS_HASH_H
