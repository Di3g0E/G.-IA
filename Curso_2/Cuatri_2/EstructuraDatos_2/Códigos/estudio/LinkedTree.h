//
//

#ifndef ESTUDIO_LINKEDTREE_H
#define ESTUDIO_LINKEDTREE_H

#include <memory>
#include <list>
#include <iostream>

template <typename T>
class LinkedTree{
public:
    template <typename S>
    class Node{
        friend class LinkedTree;
        S info;
        Node<S>* parent;
        std::list<std::shared_ptr<Node<S>>> children;
    };

    LinkedTree(): root(nullptr){}
    LinkedTree(Node<T>* node) : root(std::shared_ptr<Node<T>>(node)){}

    bool isEmpty() {return root == nullptr;}
    bool isRoot(Node<T>* node) {return node == root.get();}
    bool isLeaf(Node<T>* node) {return node->children.size() == 0;}
    bool isInternal(Node<T>* node) {return !isLeaf(node);}

    Node<T>* getRoot() {return root.get();}
    T getElement(Node<T>* node) {return node->info;}
    Node<T>* getParent(Node<T>* node) {return node->parent;}
    std::list<std::shared_ptr<Node<T>>> getChildren(Node<T>* node) {return node->children;}

    void add(T e, Node<T>* parent = nullptr){
        if (parent == nullptr && root != nullptr) {
            std::cout<<"El root no está vacío.\n";
        } if (isEmpty()) {
            root = std::make_shared<Node<T>>(e, nullptr);
        }
        Node<T> aux = std::make_shared<Node<T>>(e, parent);
        parent->children.push_front(aux);
    }

    std::shared_ptr<Node<T>> cut(Node<T>* node){
        auto parent = node->parent;
        parent->children.remove(node);
        node->parent = nullptr;

        return LinkedTree<Node<T>>(node);
    }

    void attach(LinkedTree<Node<T>> tree, Node<T>* node){
        auto aux = tree.getRoot();
        node->children.push_front(aux);
        aux->parent = node;
    }

    bool contains(Node<T>* node){
        if (!isEmpty()){
            auto aux = root.get();
            while (aux != node && aux != nullptr) {
                for (const auto &child: aux->children) {
                    contains(node);
                }
            }
            if (aux == nullptr) return 0;
            return 1;
        } return 0;
    }

    void remove(Node<T>* node) {
        if (!root) return;
        if (node == root.get()){
            auto count_children = node->children.size();
            if (count_children == 0) {
                root == nullptr;
            } else if (count_children > 1) {
                std::cout<<"No se puede borrar la raiz.\n";
            } else {root = root->children.front();}
        } else {
            Node<T> *parent = node->parent;
            auto it = parent->children.begin();
            for (; it != parent->children.end();) {
                if (*it.get() == node) break;
                ++it;
            }
            for (auto &child: node->children) {
                child->parent = parent;
                parent->children.push_front(child);
            }
            parent->children.erase(it);
        }
    }

private:
    std::shared_ptr<Node<T>> root = nullptr
};

#endif //ESTUDIO_LINKEDTREE_H
