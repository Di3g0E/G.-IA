//
// Created by Diego on 29/02/2024.
//

#ifndef ESTUDIOPRACTICA_LCRSTREE_H
#define ESTUDIOPRACTICA_LCRSTREE_H

#include <memory>

template <typename T>
class LCRSTree{
public:
    template <typename S>
    class Node{
        friend class LCRSTree;
        S info;
        Node<S>* parent;
        std::shared_ptr<Node<S>> sibling;
        std::shared_ptr<Node<S>> leftChildren;

        bool operator==(Node<S> node){
            return (node.info == info) && (node.parent == parent) && (node.sibling == sibling) && (node.leftChildren == leftChildren);
        }
    };

    bool isEmpty(){return root == nullptr;}
    bool isRoot(Node<T> node){return node == root;}
    bool isLeave(Node<T> node){return node.leftChildren == nullptr;}
    bool isInternal(Node<T> node){return !isLeave(node);}

    auto getInfo(const Node<T>& node){return node.info;}
    auto getParent(const Node<T>& node){return node.parent;}
    auto getSibling(const Node<T>& node){return node.sibling;}
    auto getChild(const Node<T>& node){return node.leftChildren;}

    std::shared_ptr<Node<T>> add(T e, Node<T> parent = nullptr){}

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_LCRSTREE_H
