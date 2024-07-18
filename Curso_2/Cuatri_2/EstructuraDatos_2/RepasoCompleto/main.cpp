#include <iostream>
//#include "BasicGraph.h"
#include "BinaryTree.h"
//#include "LinkedTree.h"
//#include "LCRSTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    /*
    // Crear un árbol binario de enteros
    BinaryTree<int> tree;

    // Agregar nodos al árbol
    tree.add(10);
    tree.add(5);
    tree.add(20);
    tree.add(3);
    tree.add(7);
    tree.add(15);
    tree.add(30);

    // Imprimir el árbol en preorden
    std::cout << "Preorder traversal:" << std::endl;
    Iterable<PreorderIterator<BinaryTree<int>>, PreorderIterator<BinaryTree<int>>> preorder(tree);
    for (auto it = preorder.begin(); it != preorder.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Imprimir el árbol en inorden
    std::cout << "Inorder traversal:" << std::endl;
    Iterable<InorderIterator<BinaryTree<int>>, InorderIterator<BinaryTree<int>>> inorder(tree);
    for (auto it = inorder.begin(); it != inorder.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    */

    /*
    LinkedTree<int> tree;

    // Agregar nodos al árbol
    auto root = tree.add(1);
    auto child1 = tree.add(2, root);
    auto child2 = tree.add(3, root);
    auto child3 = tree.add(4, root);
    auto grandchild1 = tree.add(5, child1);
    auto grandchild2 = tree.add(6, child1);
    auto grandchild3 = tree.add(7, child2);

    // Verificar si el árbol contiene ciertos elementos
    std::cout << "Contains 1: " << tree.contains(1) << std::endl;
    std::cout << "Contains 6: " << tree.contains(6) << std::endl;
    std::cout << "Contains 10: " << tree.contains(10) << std::endl;

    // Cortar un subárbol y mostrar la información del nuevo árbol
    LinkedTree<int> subtree = tree.cut(child1);
    std::cout << "Subtree root info after cut: " << subtree.getInfo(subtree.getRoot()) << std::endl;

    // Adjuntar el subárbol cortado a un nuevo nodo
    tree.attach(child3, subtree);
    std::cout << "Tree contains 2 after reattachment: " << tree.contains(2) << std::endl;

    // Remover un nodo y verificar los cambios
    tree.remove(child2);
    std::cout << "Tree contains 3 after removal: " << tree.contains(3) << std::endl;
    std::cout << "Tree contains 7 after removal of parent: " << tree.contains(7) << std::endl;
     */

    return 0;
}
