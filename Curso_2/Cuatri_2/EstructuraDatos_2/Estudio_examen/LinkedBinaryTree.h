//
// Created by Diego on 18/05/2024.
//

#ifndef UNTITLED_LINKEDBINARYTREE_H
#define UNTITLED_LINKEDBINARYTREE_H

#include <memory>
#include <stack>
#include <iostream>

template <typename T>
class LinkedBinaryTree{
public:
    using type = T;
    template <typename S>
    class Node{
        friend class LinkedBinaryTree;
        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> leftChild = nullptr;
        std::shared_ptr<Node<S>> rightChild = nullptr;
    };

    T getInfo(Node<T>* node)                const { return node->info; }
    Node<T>* getRoot()                      const { return root.get(); }
    Node<T>* getParent(Node<T>* node)       const { return node->parent; }
    Node<T>* getLeftChild(Node<T>* node)    const { return node->leftChild.get(); }
    Node<T>* getRightChild(Node<T>* node)   const { return node->rightChild.get(); }

    bool isEmpty()                  const { return (root == nullptr); }
    bool isRoot(Node<T>* node)      const { return (node == root.get()); }
    bool isLeaf(Node<T>* node)      const { return ((node->leftChild == nullptr) && (node->rightChild == nullptr)); }
    bool isInternal(Node<T>* node)  const { return !isLeaf(node); }

    Node<T>* addRoot(const T& info) {
        root = std::make_shared<Node<T>>();
        root->info = info;
        return root.get();
    }

    Node<T>* addLeft(const T& info, Node<T>* node) {
        node->leftChild = std::make_shared<Node<T>>();
        node->leftChild->info = info;
        node->leftChild->parent = node;
        return node->leftChild.get();
    }

    Node<T>* addRight(const T& info, Node<T>* node) {
        node->rightChild = std::make_shared<Node<T>>();
        node->rightChild->info = info;
        node->rightChild->parent = node;
        return node->rightChild.get();
    }

    void printTree() const {
        printTree(root.get(), 0);
    }

    Node<T>* add(T info) {
        if (root == nullptr) {
            root = std::make_shared<Node<T>>(info);
            return root.get();
        }
        Node<T>* node = root.get();
        while (true) {
            if (info < getInfo(node)) {
                if (node->leftChild == nullptr) {
                    node->leftChild = std::make_shared<Node<T>>(info);
                    node->leftChild->parent = node;
                    return node->leftChild.get();
                }
                node = node->leftChild.get();
            } else if (info > getInfo(node)) {
                if (node->rightChild == nullptr) {
                    node->rightChild = std::make_shared<Node<T>>(info);
                    node->rightChild->parent = node;
                    return node->rightChild.get();
                }
                node = node->rightChild.get();
            } else { return node; }
        }
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;

    void printTree(const Node<T>* node, int depth) const {
        if (node != nullptr) {
            printTree(node->rightChild.get(), depth + 1);
            std::cout << std::string(depth * 4, ' ') << node->info << std::endl;
            printTree(node->leftChild.get(), depth + 1);
        }
    }
};


template <typename T>
class PreorderIterator{
public:
    PreorderIterator() : t(), p() {}
    PreorderIterator(T tree) : t(tree), p() { p.push(t.getRoot()); }

    PreorderIterator& operator++() {
        auto e = p.top();
        p.pop();
        auto d = t.getRight(e);
        if (d) p.push(d);
        auto i = t.getLeft(e);
        if (i) p.push(i);
        return *this;
    }

    PreorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getInfo(p.top());
    }

    bool operator!=(const PreorderIterator& other) {
        bool d = (p.empty() != other.p.empty());
        return d;
    }

private:
    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};


template <typename T>
class InorderIterator{
public:
    InorderIterator() : t(), p() {}
    InorderIterator(T tree) : t(tree), p() { traverseLeft(t.getRoot()); }

    InorderIterator& operator++(){
        auto e = t.getRightChild(p.top());
        p.pop();
        traverseLeft(e);
        return *this;
    }

    InorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getInfo(p.top());
    }

    bool operator!=(const InorderIterator& other) {
        bool d = (p.empty() != other.p.empty());
        return d;
    }

private:
    void traverseLeft(typename T::Node<typename T::type>* node) {
        while (node) {
            p.push(node);
            node = t.getLeftChild(node);
        }
    }

    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};


template <typename T, typename I>
class Iterable{
public:
    Iterable(T begin) : b(I(begin)), e(I()) {}
    auto begin() { return b; }
    auto end() { return e; }
private:
    I b;
    I e;
};


/*
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
            node = nullptr; // Dejar que shared_ptr gestione la eliminación
        }
    }


private:
    std::shared_ptr<Node<T>> root = nullptr;
};
 */

#endif //UNTITLED_LINKEDBINARYTREE_H
