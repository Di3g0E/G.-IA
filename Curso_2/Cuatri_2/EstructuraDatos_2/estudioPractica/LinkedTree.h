//
// Created by Diego on 14/02/2024.
//

#ifndef ESTUDIOPRACTICA_LINKEDTREE_H
#define ESTUDIOPRACTICA_LINKEDTREE_H

#include <memory>
#include <list>

template <typename T>
class LinkedTree{
public:
    template <typename S>
    class Node{
        friend class LinkedTree;
        S info;
        Node<S>* parent = nullptr;
        std::list<std::shared_ptr<Node<S>>> children;
    };

    LinkedTree() : root(nullptr) {}
    LinkedTree(Node<T>* node) : root(std::shared_ptr(node)) {}

    bool isEmpty() {return root == nullptr;}
    bool isRoot(Node<T>* node) {return node == root.get();}
    bool isLeaf(Node<T>* node) {return node->children.size() == 0;}
    bool isInternal(Node<T>* node) {return !isLeaf(node);}

    Node<T>* getRoot() {return root.get();}
    T getElement(Node<T>* node) {return node->info;}
    Node<T>* getParent(Node<T>* node) {return node->parent;}
    std::list<std::shared_ptr<Node<T>>> getChildren(Node<T>* node) { return node->children;}

    Node<T>* add(T e, Node<T>* parent = nullptr){
        if ((parent == nullptr) && (root != nullptr)){
            std::cout<<"ERROR, root no vacio\n";
        } else if(isEmpty()){
            root = std::make_shared<Node<T>>(e, nullptr);
            return root.get();
        } else {
            auto aux = std::make_shared<Node<T>>(e, parent);
            parent->children.push_front(aux);
            return aux.get();
        }
        return nullptr;
    }

    Node<T>* cut(Node<T>* node){
        auto parent = node->parent;
        parent->children.remove(node);
        node->parent = nullptr;

        return LinkedTree<Node<T>>(node);
    }

    void attach(Node<T>* node, LinkedTree<Node<T>> subTree){
        auto root_subTree = subTree.getRoot();
        root_subTree->parent = node;
        node->children.push_front(root_subTree);
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_LINKEDTREE_H
