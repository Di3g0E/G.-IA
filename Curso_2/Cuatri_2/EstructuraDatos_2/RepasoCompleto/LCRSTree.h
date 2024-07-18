//
// Created by Diego on 23/05/2024.
//

#ifndef REPASOCOMPLETO_LCRSTREE_H
#define REPASOCOMPLETO_LCRSTREE_H

#include <memory>
#include <list>
#include <iostream>
#include <unordered_set>

template <typename T>
class LCRSTree{
public:
    template <typename S>
    class Node{
        friend class LCRSTree;

        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> leftChild = nullptr;
        std::shared_ptr<Node<S>> rightSibling = nullptr;

        bool operator==(Node<S>* node) {
            return (info == node->info) && (parent == node->parent) && (leftChild == node->leftChild) && (rightSibling == node->rightSibling);
        }
    };

    class ChildIterator{
    public:
        ChildIterator(std::shared_ptr<Node<T>> node) :it(node) {}

        ChildIterator& operator++(){
            it = it->rightSibling;
            return *this;
        }

        ChildIterator& operator++(int){
            auto tmp(*this);
            operator++();
            return tmp;
        }

        auto operator*(){ return it; }

        bool operator!=(const ChildIterator& other){ return it != other.it; }

    private:
        std::shared_ptr<Node<T>> it;
    };

    class WithoutSiblingIterator{
    public:
        WithoutSiblingIterator(typename LCRSTree<T>::Node<T>* node) :t(node) {}

        WithoutSiblingIterator& operator++(){
            if(t){
                t = t->rightSibling;
                while (t && t->parent && (t->parent->leftChild == t)){
                    t = t->parent->rightSibling;
                }
            }
            return *this;
        }

        WithoutSiblingIterator& operator++(int){
            auto tmp(*this);
            operator++();
            return tmp;
        }

        auto operator*() { return t; }

        bool operator!=(const WithoutSiblingIterator& other) { return (t != other.t); }

    private:
        LCRSTree<T>::Node<T>* t;
    };

    template <typename S>
    class ChildIterable{
    public:
        ChildIterable(std::shared_ptr<Node<S>> node) :node(node) {}
        auto begin() { return ChildIterator(node); }
        auto end() { return ChildIterator(nullptr); }

    private:
        std::shared_ptr<Node<S>> node = nullptr;
    };

    LCRSTree() :root(nullptr) {}
    LCRSTree(Node<T>* node) :root(node) {}

    T getInfo(Node<T>* node)                const { return node->info; }
    Node<T>* getRoot()                      const { return root.get(); }
    Node<T>* getParent(Node<T>* node)       const { return node->parent; }
    Node<T>* getLeftChild(Node<T>* node)    const { return node->leftChild.get(); }
    Node<T>* getRightSibling(Node<T>* node) const { return node->rightSibling; }
    ChildIterable<T> getChildren(Node<T>* node) const{ return ChildIterable(node->leftChild); }

    bool isEmpty()                          const { return (root == nullptr); }
    bool isRoot(Node<T>* node)              const { return (node == root.get()); }
    bool isLeaf(Node<T>* node)              const { return (node->leftChild == nullptr); }
    bool isInternal(Node<T>* node)          const { return !isLeaf(node); }

    Node<T>* add(T info, Node<T>* parent = nullptr){
        if ((parent == nullptr) && (root != nullptr)){
            std::cout<<"Error, root no vacio.\n";
        } else if (parent == nullptr){
            root = std::make_shared<Node<T>>(info);
            elements.insert(info);
            return root.get();
        } else {
            auto node = std::make_shared<Node<T>>(info);
            node->parent = parent;
            if(parent->leftChild == nullptr) parent->leftChild = node;
            else {
                auto sibling = parent->leftChild;
                while (sibling->rightSibling != nullptr){
                    sibling = sibling->rightSibling;
                }
                sibling->rightSibling = node;
            }
            elements.insert(info);
            return node.get();
        }
        return nullptr;
    }

    LCRSTree<T> cut(Node<T>* node){
        if (node) {
            std::shared_ptr<Node<T>> treeRoot;
            if (node->parent->leftChild == node) {
                node->parent->leftChild = node->rightSibling;
                treeRoot = node->parent->leftChild;
            }
            else {
                auto aux = node->parent->leftChild;
                while (aux->rightSibling != node){ aux = aux->rightSibling; }
                aux = node->rightSibling;
                treeRoot = aux->rightSibling;
            }
            node->parent = nullptr;
            node->rightSibling = nullptr;
            return LCRSTree(treeRoot);
        }
        return nullptr;
    }

    void attach(Node<T>* node, LCRSTree<T> subTree){
        if(node){
            if(node->leftChild == nullptr){
                node->leftChild = subTree.root;
            } else {
                auto aux = node->leftChild;
                while (aux->rightSibling != nullptr){ aux = aux->rightSibling; }
                aux->rightSibling = subTree.root;
            }
            subTree.root->parent = node;
        }
    }

    bool contains(T e){ return elements.contains(e); }

    void remove(Node<T>* node){
        if(!root) return;
        if(isRoot(node)){
            if(node->leftChild->rightSibling != nullptr){
                std::cout<<"No se puede eliminar la raiz.\n";
                return;
            } else if(node->leftChild == nullptr) {
                root = nullptr;
            } else {
                node->leftChild->parent = nullptr;
                root = node->leftChild;
            }
        } else {
            auto child = node->leftChild;
            while (child != nullptr){
                child->parent = node->parent;
                child = child->rightSibling;
            }
            child->rightSibling = node->rightSibling;
            node->parent->leftChild = node->leftChild;
            if(node->parent->leftChild == node) node->parent->leftChild = node->leftChild;
            else {
                auto aux = node->parent->leftChild;
                while (aux->rightSibling != node) { aux = aux->rightSibling; }
                aux->rightSibling = node->leftChild;
            }
        }
    }

    void printChildren(Node<T>* node) const {
        if (node == nullptr) std::cout << "El nodo es nulo." << std::endl;
        else {
            ChildIterable<T> children = getChildren(node);
            for (auto it = children.begin(); it != children.end(); ++it) { std::cout << (*it)->info << " "; }
            std::cout << std::endl;
        }
    }


private:
    std::shared_ptr<Node<T>> root = nullptr;
    std::unordered_set<Node<T>> elements;
};

#endif //REPASOCOMPLETO_LCRSTREE_H
