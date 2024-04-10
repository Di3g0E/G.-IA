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

    std::shared_ptr<Node<T>> getParent(Node<T> node) {return node.parent;}
    std::shared_ptr<Node<T>> getRoot(){return root;}

    bool isRoot(Node<T> node) {return node == *root;}
    bool isLeaf(Node<T> node) {return node.children.size() == 0;}
    bool isInternal(Node<T> node) {return !isLeaf(node);}

    std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr) {          // add function
        if (parent == nullptr) {
            root = std::make_shared<Node<T>>(e, nullptr);                                   // root->info = e; root->parent = nullptr; root->children inicializa lista vacía
            return root;
        } else {
            auto child = std::make_shared<Node<T>>(e, parent);
            parent->children.push_front(child);
            return child;
        } // if (parent == nullptr)
    }

    std::list<std::shared_ptr<Node<T>>> getChildren(Node<T> node) {return node.children;}   // getChildren function

    LinkedTree<T> cut(std::shared_ptr<Node<T>> node) {                                      // cut function
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

    LinkedTree<T> atach(Node<T> parent, std::shared_ptr<Node<T>> node) {                    // atach function
        parent.children.push_front(node);
        node->parent = parent;
    }

    // Ejercicios propuestos
    bool EsPadreNoAbuelo(Node<T> *nodo) {return nodo->children.size() >= 1 && nodo->children.children.size() == 0;}
    bool EsTioSinHijos(Node<T> *nodo) {return nodo->parent.children.size() >= 1 && nodo->children.size() == 0;}

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

template <typename T>
class LCRSTree {
public:

    template <typename S>
    struct Nodo {
        S info;
        std::shared_ptr<Nodo<S>> parent = nullptr;
        std::shared_ptr<Nodo<S>> leftChild = nullptr;
        std::shared_ptr<Nodo<S>> rightSibling = nullptr;
    };

    template <typename S>
    class SiblingsIterator {
    public:
        SiblingsIterator(std::shared_ptr<Nodo<S>> node) : it(node) {};

        SiblingsIterator& operator++() {
            it = it->rightSibling;
            if (it != nullptr) {
                it = it->rightSibling;
                return it;
            }
        }   // ++i;
        
        SiblingsIterator& operator++(int) {
            auto tmp = it;
            operator++();
            return tmp;
        }   // i++;

        S operator*() {
            return it;
        }

        bool operator==(const S& rhs) {
            return it == rhs;
        }

    private:
        S it;
    };

    template <typename S>
    class Iterable {
    public:
        SiblingsIterator<S> begin() {return b;}
        SiblingsIterator<S> end() {return e;}

    private:
        SiblingsIterator<S> b;
        SiblingsIterator<S> e;
    };

    bool isLeaf(Nodo<T> node) {return node.leftChild == nullptr;}
    bool isInternal(Nodo<T> node) {return !isLeaf(node);}

    std::shared_ptr<Nodo<T>> add(T e, std::shared_ptr<Nodo<T>> parent = nullptr) {
        if ((parent == nullptr) && (root != nullptr)) {
            // std::cout<<ERROR;
        } else if (parent == nullptr) {
            root = std::make_shared<Nodo<T>>(e, nullptr, nullptr, nullptr);
        } else {
            auto aux = std::make_shared<Nodo<T>>(e, parent, nullptr, nullptr);
            if (parent->leftChild == nullptr) {
                parent->leftChild = aux;
            } else {
                aux->rightSibling = parent->leftChild;
                parent->leftChild = aux;
            }   // if parent no child
            return aux;
        }   // if no root
    }

    Iterable<T> children(Nodo<T> node) {
        return Iterable{node.leftchild, nullptr};
    }

    LCRSTree<Nodo<T>> cut(Nodo<T> e, std::shared_ptr<Nodo<T>> node) {}

private:
    std::shared_ptr<Nodo<T>> root;
};

#endif //ESTUDIOPRACTICA_ARBOLNARIO_H
