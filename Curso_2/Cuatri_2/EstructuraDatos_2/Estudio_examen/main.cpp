#include <iostream>
#include "LinkedBinaryTree.h"
//#include "BinaryTree.h"

/*
template <typename T>
class PosorderIterator {
public:
    PosorderIterator() : t(), p() {}
    PosorderIterator(T t) : t(t), p() {traverseLeftLeaf(t.getRoot());}

    PosorderIterator& operator++() {
        auto e = p.top();
        p.pop();

        if ((t.getParent(e)) && (e == t.getLeftChild(p.top()))) {
            traverseLeftLeaf(t.getRightChild(p.top()));
        }
        return *this;
    }

    PosorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getInfo(p.top());
    }

    bool operator!=(const PosorderIterator& other) {
        bool d = (p.empty() != other.p.empty());
        return d;
    }
private:
    void traverseLeftLeaf(typename T::Node<typename T::type>* node) {
        while (node) {
            p.push(node);
            auto aux = node;
            node = t.getLeftChild(node);
            if (!node) node = t.getRightChild(aux);
        }
    }

    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};
*/

int main() {
    /*
    BinaryTree<int> t;
    std::cout << "Tree is empty: " << std::boolalpha << t.isEmpty() << std::endl;

    // Añadimos algunos elementos al árbol
    auto root = t.add(10);
    auto leftChild = t.add(5);
    auto rightChild = t.add(15);

    // Comprobamos si los elementos se han añadido correctamente
    std::cout << "Root info: " << t.getInfo(root) << std::endl;
    std::cout << "Left child info: " << t.getInfo(leftChild) << std::endl;
    std::cout << "Right child info: " << t.getInfo(rightChild) << std::endl;

    std::cout << "Tree is empty: " << t.isEmpty() << std::endl;
    std::cout << "Root is root: " << std::boolalpha << t.isRoot(root) << std::endl;
    std::cout << "Left child is leaf: " << std::boolalpha << t.isLeaf(leftChild) << std::endl;
    std::cout << "Right child is internal: " << std::boolalpha << t.isInternal(rightChild) << std::endl;
*/

    LinkedBinaryTree<int> t;

    auto r = t.add(10);

    /*
    auto r = t.addRoot(42);
    auto hi = t.addLeft(15, r);
    auto hd = t.addRight(60, r);
    auto hii = t.addLeft(7, hi);
    auto hid = t.addRight(20, hi);
    auto hdi = t.addLeft(50, hd);
    auto hdd = t.addRight(67, hd);
     */

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, PreorderIterator<LinkedBinaryTree<int>>> preit(t);
    for (int i : preit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, InorderIterator<LinkedBinaryTree<int>>> inoit(t);
    for (int i : inoit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, PosorderIterator<LinkedBinaryTree<int>>> posit(t);
    for (int i : posit) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    */
    return 0;


    return 0;
}

/*
#include <iostream>
#include "LinkedBinaryTree.h"

int main() {
    LinkedBinaryTree<int> t;

    auto r = t.addRoot(42);
    auto hi = t.addLeft(15, r);
    auto hd = t.addRight(60, r);
    auto hii = t.addLeft(7, hi);
    auto hid = t.addRight(20, hi);
    auto hdi = t.addLeft(50, hd);
    auto hdd = t.addRight(67, hd);

    t.printTree();

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, PreorderIterator<LinkedBinaryTree<int>>> preit(t);
    for (int i : preit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
*/
