//
// Created by Diego on 21/02/2024.
//

#ifndef LISTASYARBOLES_LINKEDBINARYTREE_H
#define LISTASYARBOLES_LINKEDBINARYTREE_H

#include <memory>

template <typename T>
class LinkedBinaryTree {
public:
    template <typename S>
    class Node {
        friend class LinkedBinaryTree;      // Esta clase puede acceder a las funciones de Node por ser "amiga"

        S info;
        Node<S> *parent;
        std::shared_ptr<Node<S>> left;
        std::shared_ptr<Node<S>> right;
    };

    bool isEmpty() {return root == nullptr;}

    Node<T> *getRoot() {return root.get();}                             // Devuelve el puntero al root
    Node<T> *getLeftChild(Node<T> *node) {return node->left.get();}     // La función get() se usa para conseguir la parte de información del puntero creado
    Node<T> *getRightChild(Node<T> *node) {return node->right.get();}
    Node<T> *getParent(Node<T> *node) {return node->parent;}
    T getElement(Node<T> *node) {return node->info;}

    bool isRoot(Node<T> *node) {return node == root.get();}
    bool isLeaf(Node<T> *node) {return (node->left == nullptr) && (node->right == nullptr);}    // Se puede comparar diréctamente con 'nullptr' porque lo diferencia de la dirección de memoria
    bool isInternal(Node<T> *node) {return !isLeaf(node);}

    Node<T> *addRoot(T e) {
        root = std::make_shared<Node<T>>();
        root->info = e;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        // root = std::make_shared<Node<T>>(e, nullptr, nullptr, nullptr); También podría ser así
        return root.get();
    }
    Node<T> *addLeft(T e, Node<T> *parent) {
        if (parent) {
            parent->left = std::make_shared<Node<T>>();
            parent->left->info = e;
            parent->left->parent = parent;
            parent->left->left = nullptr;
            parent->left->right = nullptr;
            return parent->left.get();
        }
        return nullptr;
    }
    Node<T> *addRight(T e, Node<T> *parent) {
        if (parent) {
            parent->right = std::make_shared<Node<T>>();
            parent->right->info = e;
            parent->right->parent = parent;
            parent->left->left = nullptr;
            parent->right->right = nullptr;
            return parent->right.get();
        }
        return nullptr;
    }


private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //LISTASYARBOLES_LINKEDBINARYTREE_H
