//
// Created by Diego on 23/05/2024.
//

#ifndef REPASOCOMPLETO_BINARYTREE_H
#define REPASOCOMPLETO_BINARYTREE_H

#include <memory>
#include <stack>

template <typename T>
class BinaryTree {
public:
    using type = T;
    template <typename S>
    class Node {
        friend class BinaryTree;

        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> left = nullptr;
        std::shared_ptr<Node<S>> right = nullptr;
    };

    T getInfo(Node<T>* node)            const { return node->info; }
    Node<T>* getRoot()                  const { return root.get(); }
    Node<T>* getParent(Node<T>* node)   const { return node->parent; }
    Node<T>* getLeft(Node<T>* node)     const { return node->left.get(); }
    Node<T>* getRight(Node<T>* node)    const { return node->right.get(); }

    bool isEmpty()                      const { return (root == nullptr); }
    bool isRoot(Node<T>* node)          const { return (node == root.get()); }
    bool isLeaf(Node<T>* node)          const { return ((node->left == nullptr) && (node->right == nullptr)); }
    bool isInternal(Node<T>* node)      const { return !isLeaf(node); }

    Node<T>* add(T info) {
        if (root == nullptr) {
            root = std::make_shared<Node<T>>(info);
            return root.get();
        }
        Node<T>* node = root.get();
        while (true) {
            if (info < getInfo(node)) {
                if (node->left == nullptr) {
                    node->left = std::make_shared<Node<T>>(info);
                    node->left->parent = node;
                    return node->left.get();
                }
                node = node->left.get();
            } else if (info > getInfo(node)) {
                if (node->right == nullptr) {
                    node->right = std::make_shared<Node<T>>(info);
                    node->right->parent = node;
                    return node->right.get();
                }
                node = node->right.get();
            } else { return node; }
        }
    }

    Node<T>* find(T info){
        auto node = getRoot();
        while (node || (getInfo(node) == info)){
            if(getLeft(node) && (info < getInfo(node))) { node = getLeft(node); }
            if(getRight(node) && (info > getInfo(node))) { node = getRight(node); }
            else break;
        }
        if(getInfo(node) == info) { return node; }
        else {
            std::cout << "No existe el nodo.\n";
            return nullptr;
        }
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

template <typename T>
class PreorderIterator {
public:
    PreorderIterator() :t(), p() {}
    PreorderIterator(T tree) : t(tree), p() {
        if (tree.getRoot()) { p.push(t.getRoot()); }
    }

    PreorderIterator& operator++(){
        if (!p.empty()){
            auto e = p.top();
            p.pop();
            auto d = t.getRight(e);
            if (d) p.push(d);
            auto i = t.getLeft(e);
            if (i) p.push(i);
        }
        return *this;
    }

    PreorderIterator& operator++(int){
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() const {
        return t.getInfo(p.top());
    }

    bool operator!=(const PreorderIterator& other) const {
        auto d = (p.empty() != other.p.empty());
        return d;
    }

private:
    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};

template <typename T>
class InorderIterator{
public:
    InorderIterator() :t(), i() {}
    InorderIterator(const T& tree) :t(tree), i() { transverseLeft(t.getRoot()); }

    InorderIterator& operator++(){
        if (i.empty()){
            auto e = t.getRight(i.top());
            i.pop();
            transverseLeft(e);
        }
        return *this;
    }

    InorderIterator& operator++(int){
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*(){
        return t.getInfo(i.top());
    }

    bool operator!=(const InorderIterator& other){
        auto d = (i.empty() != other.i.empty());
        return d;
    }

private:
    void transverseLeft(typename T::Node<typename T::type>* node) {
        while (node){
            i.push(node);
            node = t.getLeft(node);
        }
    }
    T t;
    std::stack<typename T::Node<typename T::type>*> i;
};

template <typename T, typename I>
class Iterable{
public:
    Iterable(T begin) :b(begin), e(I()) {}
    auto begin() {return b;}
    auto end() {return e;}

private:
    I b, e;
};

#endif //REPASOCOMPLETO_BINARYTREE_H
