//
// Created by Diego on 08/03/2024.
//

#ifndef ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H
#define ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H

#include <iostream>
#include <memory>

template <typename T>
class ArbolBinarioBusqueda {
public:
    template<typename S>
    class Node{
        S info;
        Node<S>* p = nullptr;
        std::shared_ptr<Node<S>> l = nullptr;
        std::shared_ptr<Node<S>> r = nullptr;
        int height;
    };

    void add(T e){
        std::shared_ptr<Node<T>> padre = nullptr;
        auto nodo = root;
        if (nodo){
            if (nodo->info < e){
                nodo->right.add(e);
            } else {
                nodo->left.add(e);
            }
        } else {
            nodo->info = e;
            if (!nodo.isRoot()) {
                if (nodo.esMayor(padre)) {padre->right = nodo;}
                else {padre->left = nodo;}
            }
        }
    }

    bool isRoot(Node<T>* node){
        return node == root.get();
    }

    Node<T>* insert(T e){
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>();
        node->info = e;
        node->p = nullptr;
        node->l = nullptr;
        node->r = nullptr;
        node->height = 1;
        insert(e, root.get());
        rebalance(node);
    }

    Node<T>* insert(std::shared_ptr<Node<T>> node, Node<T>* parent){
        if(parent == nullptr){
            root = node;
        } else {
            if (node < parent->info){
                if (parent->l){
                    insert(node, parent->l);
                } else {
                    parent->l = node;
                    node->p = parent;
                    updateHeight(node);
                }
            } else {
                if (parent->r){
                    insert(node, parent->r);
                } else {
                    parent->r = node;
                    node->p = parent;
                    updateHeight(node);
                }
            }
        }
    }

    void updateHeight(Node<T>* node){
        auto parent = node->parent;
        if(parent){
            parent->height = node->height + 1;
            updateHeight(parent);
        }
    }

    bool isBalanced(Node<T>* node){
        if (!node) return 1;
        auto lh = (node->l)? node->l->height : 0;
        auto rh = (node->r)? node->r->height : 0;

        return ((rh-lh) <= 1 && (rh-lh) >= -1);
    }

    void rebalance(Node<T>* node, Node<T>* a = nullptr, Node<T>* b = nullptr, Node<T>* c = nullptr){
        if (node){
            if (isBalanced(node)) {
                c = b;
                b = a;
                a = node;
                rebalance(node->p, a, b, c);
            } else {
                c = b;
                b = a;
                a = node;
                estructurate(a, b, c);
            }
        }
    }

    void estructurate(Node<T>* a, Node<T>* b, Node<T>* c){
        std::shared_ptr<Node<T>> sa, sb, sc, x, y, z, t1, t2, t3, t4;   // x,y,z -> son los nodos de menor a mayor valor; t1,t2,t3,t4 -> son los árboles hijos de esos nodos;

        bool leftcb = c == b->l;            // c es el hijo izq. de b;
        bool leftba = b == a->l;            // b es el hijo izq. de a;

        if (leftcb && leftba){              // Caso 1
            /*
            auto l = a->p->l;               // Esto puede dar problemas si a == root;
            auto r = a->p->r;               // Esto puede dar problemas si a == root;
            std::shared_ptr<Node<T>> sa = (a == l)? l:r;
            std::shared_ptr<Node<T>> sb = a->l;
            std::shared_ptr<Node<T>> sc = b->l;
             */

            x = c;
            y = b;
            z = a;

            t1 = x->l;
            t2 = x->r;
            t3 = y->r;
            t4 = z->r;

        } else if (!leftcb && leftba) {     // Caso 2
            /*
                auto l = a->p->l;
                auto r = a->p->r;
                std::shared_ptr<Node<T>> sa = (a == l) ? l : r;
                std::shared_ptr<Node<T>> sb = a->l;
                std::shared_ptr<Node<T>> sc = b->r;
                */

                x = b;
                y = c;
                z = a;

                t1 = b->l;
                t2 = c->l;
                t3 = c->r;
                t4 = a->r;

        } else if (leftcb && !leftba) {     // Caso 3

            x = a;
            y = c;
            z = b;

            t1 = x->l;
            t2 = y->l;
            t3 = y->r;
            t4 = z->r;

        } else if (!leftcb && !leftba) {    // Caso 4

            x = a;
            y = b;
            z = c;

            t1 = x->l;
            t2 = y->l;
            t3 = z->l;
            t4 = z->r;
        }


        if(a->p) { a->p = y; }
        else { root = y; }
        y->l = x;
        y->r = z;
        x->l = t1;
        x->r = t2;
        z->l = t3;
        z->r = t4;

    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

#endif //ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H
