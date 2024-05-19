//
// Created by Diego on 05/03/2024.
//

#ifndef REPASOCOMPLETO_LINKEDTREE_H
#define REPASOCOMPLETO_LINKEDTREE_H

#include <memory>
#include <vector>

template <typename T>
class LinkedTree{
public:
    template<typename S>
    class Node{
        friend class LinkedTree;
        S info;
        std::shared_ptr<Node<S>> parent = nullptr;
        std::vector<std::shared_ptr<Node<S>>> children = nullptr;

        bool operator==(const Node<S>& node){
            return (node.info == info) && (node.parent == parent) && (node.children == children);
        }
    };

    std::shared_ptr<Node<T>> gerRoot(){return root;}
    T getElement(const Node<T>& node){return node.info;}
    std::shared_ptr<Node<T>> getParent(const Node<T>& node){return node.parent;}
    std::vector<std::shared_ptr<Node<T>>> getChildren(const Node<T>& node){return node.children;}

    bool isEmpty(){return root = nullptr;}
    bool isRoot(const Node<T>& node){return node == root;}
    bool isLeave(const Node<T>& node){return node.children != nullptr;}
    bool isInternal(const Node<T>& node){return !isLeave(node);}

    std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr){
        auto node = std::make_shared<Node<T>>(e, parent);
        parent->children.push_back(node);
        return node;
    }
    void cut(std::shared_ptr<Node<T>> node){
        auto parent = node->parent;
        auto aux = parent->children;
        int i = 0;
        node->parent = nullptr;
        while (node != aux[i]){
            ++i;
        }
        if (node == aux[i]){aux[i] = nullptr;}
    }
    void concat(std::shared_ptr<Node<T>> node, std::shared_ptr<Node<T>> root){
        node->children.push_back(root);
        root->parent = node;
    }

    bool parentNotGrandparent(const Node<T>& node){
        if (node.children.size() != 0){
            for (const auto& e:node.children) {
                if (e.children.size() != 0){return 0;}
                return 1;
            }return 0;
        }
    }
    bool uncleWithoutChildren(const Node<T>& node){
        auto parent = node.parent;
        return (parent->children.size() > 1) && (node.children.size() == 0);
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //REPASOCOMPLETO_LINKEDTREE_H
