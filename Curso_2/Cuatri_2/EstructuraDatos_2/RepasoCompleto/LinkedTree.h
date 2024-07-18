//
// Created by Diego on 23/05/2024.
//

#ifndef REPASOCOMPLETO_LINKEDTREE_H
#define REPASOCOMPLETO_LINKEDTREE_H

#include <memory>
#include <list>
#include <iostream>

template <typename T>
class LinkedTree {
public:
    template <typename S>
    class Node {
        friend class LinkedTree;

        S info;
        Node<S> *parent;
        std::list<std::shared_ptr<Node<S>>> children;

        bool operator==(Node<S>* node){
            return (info == node->info) && (parent == node->parent) && (children == node->children);
        }
    };

    LinkedTree() :root(nullptr) {}
    LinkedTree(std::shared_ptr<Node<T>> node) :root(node) {}

    T getInfo(Node<T>* node)                        const { return node->info; }
    Node<T>* getRoot()                              const { return root.get(); }
    Node<T>* getParent(Node<T>* node)               const { return node->parent; }
    std::list<Node<T>> getChildren(Node<T>* node)   const { return node->children; }

    bool isEmpty()                                  const { return (root == nullptr); }
    bool isRoot(Node<T>* node)                      const { return (node == root.get()); }
    bool isLeaf(Node<T>* node)                      const { return (node->children.size() == 0); }
    bool isInternal(Node<T>* node)                  const { return !isLeaf(node); }

    Node<T>* add(T info, Node<T>* parent = nullptr){
        if ((parent == nullptr) && (root != nullptr)) {
            std::cout<<"Error, root no vacio.\n";
        } else if (parent == nullptr) {
            root = std::make_shared<Node<T>>(info);
            root->parent = nullptr;
            return root.get();
        } else {
            auto node = std::make_shared<Node<T>>(info);
            node->parent = parent;
            node->parent->children.push_front(node);
            return node.get();
        }
        return nullptr;
    }

    LinkedTree<T> cut(Node<T>* node){
        if (node != getRoot()){
            Node<T>* parent = getParent(node);
            std::shared_ptr<Node<T>> aux;
            for(auto it = parent->children.begin(); it != parent->children.end();){
                aux = *it;
                if (aux == node){
                    parent->children.erase(it);
                    break;
                }
                ++it;
            }
            node->parent = nullptr;
            return LinkedTree(aux);
        }
        std::cout<<"No se puede cortar por la raiz.\n";
        return nullptr;
    }

    void attach(Node<T>* node, LinkedTree<T> subTree){
        auto subRoot = subTree.root;
        subRoot->parent = node;
        node->children.push_front(subRoot);
    }

    bool contains(T e){
        return containsSub(e, getRoot());
    }

    void remove(Node<T>* node){
        if(!root) return;
        if(node == getRoot()){
            auto nc = node->children.size();
            if (nc > 1) std::cout<<"No se puede eliminar la raiz.\n";
            else if (nc == 0) root == nullptr;
            else root = root->children.front();
        } else {
            auto it = node->parent->children.begin();
            for(; it != node->parent->children.end();){
                if(*it.get() == node) break;
                ++it;
            }
            for(auto& child: node->children){
                child->parent = node->parent;
                node->parent->children.push_front(child);
            }
            node->parent->children.erase(it);
        }
    }

    void remove2(Node<T>* node){
        if(!root) return;
        if(node){
            if(node == getRoot()){
                auto nc = node->children.size();
                if(nc == 0) root = nullptr;
                if(nc > 1) {
                    std::cout<<"No puedes eliminar la raiz.\n";
                    return;
                } else {
                    root = root->children.front();
                    return;
                }
            } else {

            }
        }
    }

private:
    bool containsSub(T e, Node<T>* node){
        if (node == nullptr) return false;
        if (e == getInfo(node)) return true;
        for(const auto& it: node->children){
            if (containsSub(e, it)) return true;
        }
        return false;
    }

    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //REPASOCOMPLETO_LINKEDTREE_H
