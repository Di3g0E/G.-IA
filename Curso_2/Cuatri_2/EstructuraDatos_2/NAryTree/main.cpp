#include <iostream>
#include <memory>
#include <list>
#include "LinkedTree.h"
#include "LCRSTree.h"

template <typename T>
void printTree(T t) {
    std::cout << "\n\n\nImprimir arbol\n\n";
    std::cout << "Raiz: " << t.getElement(t.getRoot()) << "\n";

    auto hs = t.getChildren(t.getRoot());

    std::cout << "hijos: ";
    for(const auto& h: hs) {
        std::cout << t.getElement(h.get()) << " ";
    }
    std::cout << "\n";

    for(const auto& h: hs) {
        auto ns = t.getChildren(h.get());

        std::cout << "nietos: ";
        for(const auto& n: ns) {
            std::cout << t.getElement(n.get()) << " ";
        }
        std::cout << " | ";
    }
    std::cout << "\n\n\n";

}

int main()
{
    std::cout<<"Hello World";

    LinkedTree<int> t;
    //LCRSTree<int> t;

    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    auto root = t.add(42);
    auto h1 = t.add(37, root);
    auto h2 = t.add(3, root);
    auto n11 = t.add(17, h1);
    auto n21 = t.add(9, h2);
    auto n22 = t.add(27, h2);
    auto n23 = t.add(81, h2);

    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    printTree(t);

    std::cout << "¿Es root Root?: " << t.isRoot(root) << "\n";
    std::cout << "¿Es h1 Root?: " << t.isRoot(h1) << "\n";
    std::cout << "¿Es n11 Root?: " << t.isRoot(n11) << "\n";
    std::cout << "¿Es hoja root?: " << t.isLeaf(root) << "\n";
    std::cout << "¿Es hoja h2?: " << t.isLeaf(h2) << "\n";
    std::cout << "¿Es hoja n22?: " << t.isLeaf(n22) << "\n";
    std::cout << "¿Es interno Root?: " << t.isInternal(root) << "\n";
    std::cout << "¿Es interno n23?: " << t.isInternal(n23) << "\n";
    std::cout << "¿Es root el padre de h1?: " << (root == t.getParent(h1)) << "\n";
    std::cout << "¿Es root el padre de n11?: " << (root == t.getParent(n11)) << "\n";
    std::cout << "¿Es h2 el padre de n21?: " << (h2 == t.getParent(n21)) << "\n";
    std::cout << "¿Es h2 el padre de n11?: " << (h2 == t.getParent(n11)) << "\n";
    std::cout << "¿Es root el abuelo de h2?: " << (root == t.getParent(t.getParent(h2))) << "\n";
    std::cout << "¿Es root el abuelo de n11?: " << (root == t.getParent(t.getParent(n11))) << "\n";

    auto tcut = t.cut(h1);

    printTree(t);

    printTree(tcut);

    t.attach(root, tcut);

    printTree(t);

    return 0;
}