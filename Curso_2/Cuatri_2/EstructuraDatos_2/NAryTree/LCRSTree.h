//
// Created by Diego on 23/02/2024.
//

#ifndef NARYTREE_LCRSTREE_H
#define NARYTREE_LCRSTREE_H

#include <iostream>
#include <memory>
#include <list>

template <typename T>
class LCRSTree {
public:
    template <typename S>
    class Node {
        friend class LCRSTree;
        S info;
        std::shared_ptr<Node<S>> parent;
        std::shared_ptr<Node<S>> leftChild;
        std::shared_ptr<Node<S>> RightSibling;

        bool operator==(Node<S> rhs) {
            return (parent == rhs.parent) && (leftChild == rhs.leftChild) && (RightSibling == rhs.RightSibling);
        }
    };

    class ChildIterator {
    public:
        ChildIterator(std::shared_ptr<Node<T>> node) : it(node) {}

        ChildIterator& operator++() {
            it = it->RightSibling;
            return *this;
        }

        ChildIterator operator++(int) {
            auto tmp(*this);
            operator++();
            return tmp;
        }

        auto operator*() {
            return it;
        }

        bool operator!=(const ChildIterator& other) {
            return it != other.it;
        }

    private:
        std::shared_ptr<Node<T>> it;
    };

    template <typename S>
    class ChildIterable {
    public:
        ChildIterable(std::shared_ptr<Node<S>> node) : node(node) {}

        auto begin() { return ChildIterator(node); }

        auto end() { return ChildIterator(nullptr); }

    private:
        std::shared_ptr<Node<S>> node=nullptr;
    };

    LCRSTree() : root(nullptr) {}
    LCRSTree(std::shared_ptr<Node<T>> node) : root(node) {}

    bool isEmpty() {return root == nullptr;}

    std::shared_ptr<Node<T>> getRoot() {return root;}
    T getElement(Node<T> node) {return node.info;}
    std::shared_ptr<Node<T>> getParent(Node<T> node) {return node.parent;}

    bool isRoot(Node<T> node) {return node == *(root);}
    bool isLeaf(Node<T> node) {return node.leftChild == nullptr;}
    bool isInternal(Node<T> node) {return !isLeaf(node);}

    std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr) {
        if ((parent == nullptr) && (root != nullptr)) {
            std::cout << "Error, root no vacío.\n";
        } else if (parent == nullptr) {
            root = std::make_shared<Node<T>>(e, nullptr);
            // root = std::make_shared<Node<T>>();
            // root->info = e;
            return root;
        } else {
            auto aux = std::make_shared<Node<T>>(e, parent);
            if (parent->leftChild == nullptr) {
                parent->leftChild = aux;
            } else {
                auto sibling = parent->leftChild;
                while (sibling->RightSibling != nullptr) {
                    sibling = sibling->RightSibling;
                }
                sibling->RightSibling = aux;
            }
            return aux;
        }
        return nullptr;
    }

    ChildIterable<T> getChildren(Node<T> node) { return ChildIterable(node.leftChild);}

    LCRSTree<T> cut(std::shared_ptr<Node<T>> node) {
        auto parent = getParent(*node);

        if (parent->leftChild == node) {
            parent->leftChild = parent->leftChild->RightSibling;
        } else {
            auto aux = parent->leftChild;
            while (aux->RightSibling != node) {
                aux = aux->RightSibling;
            }
            aux->RightSibling = aux->RightSibling->RightSibling;
        }

        node->parent = nullptr;
        node->RightSibling = nullptr;
        return LCRSTree<T>(node);
    }

    void attach(std::shared_ptr<Node<T>> node, LCRSTree<T> subt) {
        auto subroot = subt.getRoot();
        if (node->leftChild == nullptr) {
            node->leftChild = subroot;
        } else {
            auto aux = node->leftChild;
            while (aux->RightSibling != nullptr) {
                aux = aux->RightSibling;
            }
            aux->RightSibling = subroot;
        }
        subroot->parent = node;
    }


private:
    std::shared_ptr<Node<T>> root=nullptr;
};

#endif //NARYTREE_LCRSTREE_H
