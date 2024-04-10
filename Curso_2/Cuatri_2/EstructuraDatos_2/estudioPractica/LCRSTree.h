//
// Created by Diego on 29/02/2024.
//

#ifndef ESTUDIOPRACTICA_LCRSTREE_H
#define ESTUDIOPRACTICA_LCRSTREE_H

#include <memory>
#include <iostream>

template <typename T>
class LCRSTree{
public:
    template <typename S>
    class Node{
        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> sibling = nullptr;
        std::shared_ptr<Node<S>> leftChild = nullptr;
        bool operator==(Node<S>* node){
            return ((node->info == info) && (node->parent == parent) && (node->sibling == sibling) && (node->leftChild == leftChild));
        }
    };

    class ChildOperator{
    public:
        ChildOperator(std::shared_ptr<Node<T>> node) : it(node) {}

        ChildOperator& operator++(){
            auto it = it->sibling;
            return *this;
        }

    private:
        std::shared_ptr<Node<T>> it;
    };

    bool isEmpty(){return root == nullptr;}
    bool isRoot(Node<T>* node){return node == root;}
    bool isLeaf(Node<T>* node){return node->leftChild == nullptr;}
    bool isInternal(Node<T>* node){return !isLeaf(node);}

    Node<T>* getRoot(){return root.get();}
    Node<T>* getParent(Node<T>* node){return node->parent;}
    T getElement(Node<T>* node){return node->info;}
    Node<T>* getChildren(Node<T>* node){return node->leftChild;}

    Node<T>* add(T e, Node<T>* parent = nullptr){
        if((parent == nullptr) && (root != nullptr)){std::cout<<"ERROR\n";}
        else if(isRoot(parent)){
            root = std::make_shared<Node<T>>(e);
            return root;
        } else {
            auto node = std::make_shared<Node<T>>(e, parent);
            if (parent->leftChild){
                auto sibling = parent->leftChild;
                while (sibling != nullptr){sibling = sibling->sibling.get();}
                sibling = node;
            }
        }
    }


private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_LCRSTREE_H
