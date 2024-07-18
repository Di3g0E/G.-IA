//
// Created by Diego on 23/05/2024.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H

#include <memory>

template <typename T>
class BinaryTree {
public:
    template <typename S>
    class Node {
        friend class BinaryTree;
        S info;
        Node<S>* parent = nullptr;
        std::shared_ptr<Node<S>> left = nullptr;
        std::shared_ptr<Node<S>> right = nullptr;

        Node(S info) :info(info) {}
    };

    T getInfo(Node<T>* node)            const { return node->info; }
    Node<T>* getRoot()                  const { return root.get(); }
    Node<T>* getParent(Node<T>* node)   const { return node->parent; }
    Node<T>* getLeft(Node<T>* node)     const { return node->left.get(); }
    Node<T>* getRight(Node<T>* node)    const { return node->right.get(); }

    bool isEmpty() const { return (root == nullptr); }
    bool isRoot(Node<T>* node) const { return (node == root.get()); }
    bool isLeaf(Node<T>* node) const { return (node->left == nullptr) && (node->right == nullptr); }
    bool isInternal(Node<T>* node) const { return !isLeaf(node); }

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

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //UNTITLED_BINARYTREE_H
