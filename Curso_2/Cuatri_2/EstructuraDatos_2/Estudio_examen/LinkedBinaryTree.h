//
// Created by Diego on 18/05/2024.
//

#ifndef UNTITLED_LINKEDBINARYTREE_H
#define UNTITLED_LINKEDBINARYTREE_H

#include <memory>

template <typename T>
class LinkedBinaryTree{
public:
    template <typename S>
    class Node{
        friend class LinkedBinaryTree;

        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> rightChild = nullptr;
        std::shared_ptr<Node<S>> leftChild = nullptr;
    };

    bool isEmpty(){return root == nullptr;}
    bool isRoot(Node<T>* node){return node == root.get();}
    bool isLeaf(Node<T>* node){return (node->rightChild == nullptr) && (node->leftChild == nullptr);}
    bool isInternal(Node<T>* node){return !isLeaf(node);}

    Node<T>* getRoot(){return root.get();}
    Node<T>* getLeftChild(Node<T>* node){return node->leftChild.get();}
    Node<T>* getRightChild(Node<T>* node){return node->rightChild.get();}
    Node<T>* getParent(Node<T>* node){return node->parent;}
    T getInfo(Node<T>* node){return node->info;}

    Node<T>* add(const T& info){
        if (getRoot() == nullptr) {
            root = std::make_shared<Node<T>>(info);
            return root.get();
        }
        Node<T>* node = getRoot();
        while (true){
            if (info > getInfo(node)) {
                if (node->rightChild == nullptr){
                    node->rightChild = std::make_shared<Node<T>>(info);
                    node->rightChild->parent = node;
                    return node->rightChild.get();
                }
                node = node->rightChild.get();
            }
            if (info < getInfo(node)) {
                if (node->leftChild == nullptr){
                    node->leftChild = std::make_shared<Node<T>>(info);
                    node->leftChild->parent = node;
                    return node->leftChild.get();
                }
                node = node->leftChild.get();
            }
            else return node;
        }
    }

    Node<T>* find(const T& info, Node<T>* node){
        if (!node) return nullptr;
        bool flag = false;
        if (info == getInfo(node)) {
            flag = true;
            return node;
        }
        if (!flag) find(info, getLeftChild(node));
        find(info, getRightChild(node));
        return nullptr;
    }

    void remove(const T& info){
        Node<T>* node = find(info, getRoot());
        if (node){
            
        }
    }


private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //UNTITLED_LINKEDBINARYTREE_H
