#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

template<typename Iterator>
class EvenPosIterator {
public:
    EvenPosIterator(Iterator start, Iterator end) : it(start), end(end) {}

    EvenPosIterator& operator++() {
        ++it;
        if ((it != end) && (it % 2 != 0)) { ++it; }
        return *this;
    }
    
    EvenPosIterator operator++(int) {
        EvenPosIterator tmp(*this);
        operator++();
        return tmp;
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


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::forward_list<int> f = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
    EvenPosIterable vectorEvenPosIterable(v);
    for (int i : vectorEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    EvenPosIterable listEvenPosIterable(l);
    for (int i : listEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    EvenPosIterable forwardEvenPosIterable(f);
    for (int i : forwardEvenPosIterable) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
