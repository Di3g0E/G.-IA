#include <iostream>
#include "LinkedBinaryTree.h"

int main() {
    LinkedBinaryTree<int> tree;
    auto root = tree.add(10);
    auto leftChild = tree.add(5);
    auto rightChild = tree.add(15);

    // Pruebas básicas
    if (tree.isRoot(root)) {
        std::cout << "Root: " << tree.getInfo(root) << std::endl;
    }
    if (tree.isLeaf(leftChild)) {
        std::cout << "Left child is a leaf: " << tree.getInfo(leftChild) << std::endl;
    }
    if (tree.isLeaf(rightChild)) {
        std::cout << "Right child is a leaf: " << tree.getInfo(rightChild) << std::endl;
    }
    if (!tree.isInternal(rightChild)) {
        std::cout << "Right child is not an internal node.";
    }

    return 0;
}
