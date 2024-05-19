//
// Created by Diego on 23/02/2024.
//

#ifndef NARYTREE_LINKEDTREE_H
#define NARYTREE_LINKEDTREE_H

#include <iostream>
#include <memory>
#include <list>

template <typename T>
class LinkedTree {
public:
    template <typename S>
    class Node {
        friend class LinkedTree;
        S info;
        Node<S>* parent;
        std::list<std::shared_ptr<Node<S>>> children;
        bool operator==(Node<S> rhs) {
            return (info == rhs.info) && (parent == rhs.parent) && (children == rhs.children);
        }
    };

    LinkedTree() : root(nullptr) {}
    LinkedTree(Node<T>* node) : root(std::shared_ptr(node)) {}

    bool isEmpty() {return root == nullptr;}

    Node<T>* getRoot() {return root.get();}
    T getElement(Node<T>* node) {return node->info;}
    Node<T>* getParent(Node<T>* node) {return node->parent;}

    bool isRoot(Node<T>* node) {return node == root.get();}
    bool isLeaf(Node<T>* node) {return node->children.size() == 0;}
    bool isInternal(Node<T>* node) {return !isLeaf(node);}

    Node<T>* add(T e, Node<T>* parent = nullptr) {
        if ((parent == nullptr) && (root != nullptr)) {
            std::cout << "Error, root no vacío.\n";
        } else if (parent == nullptr) {
            root = std::make_shared<Node<T>>(e, nullptr);
            return root.get();
        } else {
            auto aux = std::make_shared<Node<T>>(e, parent);
            parent->children.push_front(aux);
            return aux.get();
        }
        return nullptr;
    }

    std::list<std::shared_ptr<Node<T>>> getChildren(Node<T>* node) { return node->children;}

    LinkedTree<T> cut(Node<T>* node) {
        auto parent = getParent(node);
        parent->children.remove(node);
        node->parent = nullptr;

        return LinkedTree(node);
    }

    void attach(Node<T>* node, LinkedTree<T> subt) {
        auto subroot = subt.getRoot();
        subroot->parent = node;
        node->children.push_front(subroot);
    }


private:
    std::shared_ptr<Node<T>> root=nullptr;
};

#endif //NARYTREE_LINKEDTREE_H
