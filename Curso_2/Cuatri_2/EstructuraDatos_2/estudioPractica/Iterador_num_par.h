//
// Created by Diego on 03/04/2024.
//

#ifndef ESTUDIOPRACTICA_ITERADOR_NUM_PAR_H
#define ESTUDIOPRACTICA_ITERADOR_NUM_PAR_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

template<typename Iterator>
class EvenPosIterator {
public:
    EvenPosIterator(Iterator start, Iterator end) : it(start), end(end) {if(it!= end && (*it % 2 != 0)) ++it;}

    EvenPosIterator& operator++() {
        if (it != end) ++it;
        while(it!= end && (*it % 2 != 0)) ++it;
        return *this;
    }

    EvenPosIterator operator++(int) {
        EvenPosIterator tmp(*this);
        operator++();
        if (it % 2== 0) return tmp;
        else operator++(tmp);
    }

    auto operator*() {
        return *it;
    }

    bool operator!=(const EvenPosIterator& other) {
        return it != other.it;
    }

private:
    Iterator it, end;
};

template<typename Container>
class EvenPosIterable {
public:
    EvenPosIterable(Container& c) : c(c) {}

    auto begin() { return EvenPosIterator(c.begin(), c.end()); }

    auto end() { return EvenPosIterator(c.end(), c.end()); }

private:
    Container& c;
};

#endif //ESTUDIOPRACTICA_ITERADOR_NUM_PAR_H
