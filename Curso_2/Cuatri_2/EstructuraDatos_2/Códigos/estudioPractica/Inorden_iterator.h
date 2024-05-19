//
// Created by Diego on 04/04/2024.
//

#ifndef ESTUDIOPRACTICA_INORDEN_ITERATOR_H
#define ESTUDIOPRACTICA_INORDEN_ITERATOR_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include "LinkedTree.h"

template <typename T>
class Inorder_iterator {
public:
    Inorder_iterator(Node<T>* root) {
        current = root;
        while (current && current->left_child) {
            current = current->left_child.get();
        }
    }

    Inorder_iterator& operator++() {
        if (current) {
            if (current->right_child) {
                current = current->right_child.get();
                while (current && current->left_child) {
                    current = current->left_child.get();
                }
            } else {
                auto* parent = current->parent;
                while (parent && current == parent->right_child.get()) {
                    current = parent;
                    parent = parent->parent;
                }
                current = parent;
            }
        }
        return *this;
    }

    Inorder_iterator operator++(int) {
        Inorder_iterator temp = *this;
        ++(*this);
        return temp;
    }

    T operator*() const {
        return current->info;
    }

    bool operator!=(const Inorder_iterator& other) const {
        return current != other.current;
    }

private:
    Node<T>* current;
};

Inorder_iterator begin_inorder() {
    return Inorder_iterator(root.get());
}

Inorder_iterator end_inorder() {
    return Inorder_iterator(nullptr);
}

private:
std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_INORDEN_ITERATOR_H
