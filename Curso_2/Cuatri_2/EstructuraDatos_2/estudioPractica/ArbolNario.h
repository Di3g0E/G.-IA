//
// Created by Diego on 14/02/2024.
//

#ifndef ESTUDIOPRACTICA_ARBOLNARIO_H
#define ESTUDIOPRACTICA_ARBOLNARIO_H

#include <list>
#include <memory>

template <typename T>
class LinkedTree {
public:
    template <typename S>
    struct Node {
        S info;
        std::shared_ptr<Node<S>> parent;
        std::list<std::shared_ptr<Node<S>>> children;

        bool operator==(Node<T> rhs) {return (info == rhs.info) && (parent == rhs.parent);} // rhs = Right Hand Side; lhs = Left Hand Side
    };

    LinkedTree(std::shared_ptr<Node<T>> node) : root(node){};

    bool isEmpty() {return root == nullptr;}

    std::shared_ptr<Nodo<T>> getParent(Node<T> node) {return node.parent;}
    std::shared_ptr<Nodo<T>> getRoot(){return root;}

    bool isRoot(Node<T> node) {return node == *root;}
    bool isLeaf(Node<T> node) {return node.children.size() == 0;}
    bool isInternal(Node<T> node) {return !isLeaf(node);}

    std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr) {
        if (parent == nullptr) {
            root = std::make_shared<Node<T>>(e, nullptr);                                   // root->info = e; root->parent = nullptr; root->children inicializa lista vacía
            return root;
        } else {
            auto child = std::make_shared<Node<T>>(e, parent);
            parent->children.push_front(child);
            return child;
        } // if (parent == nullptr)
    }

    std::list<std::shared_ptr<Nodo<T>>> getChildren(Nodo<T> node) {return node.children;}

    LinkedTree<T> cut(std::shared_ptr<Node<T>> node) {
        auto parent = getParent(node);
        if (parent == nullptr) {
            auto t = *this;                                                                 // Copia del puntero de la propia variable
            root = nullptr;
            return t;
        } else {
            parent->children.remove(node);
            LinkedTree t{node};
            return t;
        }   // if (parent == nullpt
    }

    LinkedTree<T> atach(Node<T> parent, std::shared_ptr<Node<T>> node) {

    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_ARBOLNARIO_H
