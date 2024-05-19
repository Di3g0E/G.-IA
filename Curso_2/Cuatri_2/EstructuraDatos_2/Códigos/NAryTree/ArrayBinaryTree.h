//
// Created by Diego on 23/02/2024.
//

#ifndef NARYTREE_ARRAYBINARYTREE_H
#define NARYTREE_ARRAYBINARYTREE_H

#include <iostream>
#include <vector>

template <typename T>
class ArrayBinaryTree {
public:
    ArrayBinaryTree(int size) :data(size) {data[0].valid = 0};

    template <typename S>
    struct Node {
        S info;
        bool valid;
    };

    using Position = int;

    Position addRoot(T e) {
        data[0].info = e;
        data[0].valid = 1;
    }

    Position addLeftChild(T e, Position parent) {
        data[parent*2+1].info = e;
        data[parent*2+1].valid = 1;
    }

private:
    std::vector<int> data;
};

#endif //NARYTREE_ARRAYBINARYTREE_H
