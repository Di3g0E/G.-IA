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
        std::shared_ptr<Node<S>> padre;
        std::list<std::shared_ptr<Node<S>>> hijos;

        bool operator==(Node<S> rhs) {return (info == rhs.info) && (padre == rhs.padre);}
    };

    LinkedTree(std::shared_ptr<Node<T>> node) : root(node){};

    bool isEmpty() {return root == nullptr;}

    std::shared_ptr<Node<T>> getParent(const Node<T>& node) {return node.padre;}
    std::shared_ptr<Node<T>> getRoot() {return root;}
    std::shared_ptr<Node<T>> getChildren(const Node<T>& node) {return node.hijos;}

    bool isRoot(Node<T> node) {return node == *root;}
    bool isLeave(Node<T> node) {return node.hijos.size() == 0;}
    bool isInternal(Node<T> node) {return !isLeave(node);}

    std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> padre = nullptr) {
        if (padre == nullptr){
            root = std::make_shared<Node<T>>(e, nullptr);
            return root;
        } else {
            auto child = std::make_shared<Node<T>>(e, nullptr);
            padre->hijos.push_front(child);
            return child;
        }   // if
    }



private:
    std::shared_ptr<Node<T>> root;
};

#endif //ESTUDIOPRACTICA_ARBOLNARIO_H
