//
// Created by Diego on 08/03/2024.
//

#ifndef ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H
#define ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H

#include <iostream>
#include <memory>

template <typename T>
class AVLTree{
public:
    template<typename S>
    class Node{
        friend class AVLTree;
        S info;
        Node<S>* padre;
        std::shared_ptr<Node<S>> izq;
        std::shared_ptr<Node<S>> der;
        int altura;
    };

    bool isEmpty(){return raiz == nullptr;}
    bool isRaiz(Node<T>* node){return node == raiz.get();}
    bool isHoja(Node<T>* node){return (node->izq == nullptr) && (node->der == nullptr);}
    bool isInternal(Node<T>* node){return !isHoja(node);}

    Node<T>* getRaiz(){return raiz.get();}
    Node<T>* getPadre(Node<T>* node){return node->padre;}
    Node<T>* getHijoIzq(Node<T>* node){return node->izq.get();}
    Node<T>* getHijoDer(Node<T>* node){return node->der.get();}

    void upgradeAltura(Node<T>* node){
        auto padre = node->padre;
        if(padre){
            padre->altura = node->altura + 1;
            upgradeAltura(padre);
        }
    }

    Node<T>* insert(T e){
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>();
        node->info = e;
        node->padre = nullptr;
        node->izq = nullptr;
        node->der = nullptr;
        node->altura = 1;
        auto nodo = insert(node, raiz.get());
        rebalance(nodo);
        return nodo;
    }
    Node<T>* insert(std::shared_ptr<Node<T>> node, Node<T>* padre){
        if(padre == nullptr){
            raiz = node;
            return raiz.get();
        } else {
            if(node->info < padre->info){
                if(padre->izq){
                    return insert(node, padre->izq.get());
                } else {
                    padre->izq = node;
                    node->padre = padre;
                    upgradeAltura(node.get());
                    return node.get();
                }
            } else {
                if(padre->der){
                    return insert(node, padre->der.get());
                } else {
                    padre->der = node;
                    node->padre = padre;
                    upgradeAltura(node.get());
                    return node.get();
                }
            }
        }
    }

    bool isBalanceado(Node<T>* node){
        if(!node) return true;

        auto ai = (node->izq) ? node->izq->altura : 0;
        auto ad = (node->der) ? node->der->altura : 0;

        int b = ad - ai;
        return (b >= -1) && (b <= 1);
    }

    void rebalance(Node<T>* node, Node<T>* a = nullptr, Node<T>* b = nullptr, Node<T>* c = nullptr){
        if(node){
            if(isBalanceado(node)){
                c = b;
                b = a;
                a = node;
                rebalance(node->padre, a, b, c);
            } else {
                c = b;
                b = a;
                a = node;
                Estructurar(a, b, c);
            }
        }
    }
    void Estructurar(Node<T>* a, Node<T>* b, Node<T>* c){
        std::shared_ptr<Node<T>> p;
        std::shared_ptr<Node<T>> l;
        std::shared_ptr<Node<T>> r;
        if(a->padre == nullptr){
            p = raiz;
        } else {
            l = a->padre->izq;
            r = a->padre->der;
        }

        bool izqcb = c == b->izq.get();
        bool izqba = b == a->izq.get();

        std::shared_ptr<Node<T>> x = nullptr;
        std::shared_ptr<Node<T>> y = nullptr;
        std::shared_ptr<Node<T>> z = nullptr;

        std::shared_ptr<Node<T>> t1;
        std::shared_ptr<Node<T>> t2;
        std::shared_ptr<Node<T>> t3;
        std::shared_ptr<Node<T>> t4;

        if(izqcb && izqba){
            std::shared_ptr<Node<T>> sa;
            if(a->padre != nullptr){
                sa = (a == l.get()) ? l : r;
            } else {
                sa = p;
            }
            auto sb = a->izq;
            auto sc = b->izq;

            x = sc;
            y = sb;
            z = sa;

            t1 = x->izq;
            t2 = x->der;
            t3 = y->der;
            t4 = z->der;

        } else if(!izqcb && izqba){
            std::shared_ptr<Node<T>> sa;
            if(a->padre != nullptr){
                sa = (a == l.get()) ? l : r;
            } else {
                sa = p;
            }
            auto sb = a->izq;
            auto sc = b->der;

            x = sb;
            y = sc;
            z = sa;

            t1 = x->izq;
            t2 = y->izq;
            t3 = y->der;
            t4 = z->der;

        } else if(izqcb && !izqba){
            std::shared_ptr<Node<T>> sa;
            if(a->padre != nullptr){
                sa = (a == l.get()) ? l : r;
            } else {
                sa = p;
            }
            auto sb = a->der;
            auto sc = b->izq;

            x = sa;
            y = sc;
            z = sb;

            t1 = x->izq;
            t2 = y->izq;
            t3 = y->der;
            t4 = z->der;

        } else {
            std::shared_ptr<Node<T>> sa;
            if(a->padre != nullptr){
                sa = (a == l.get()) ? l : r;
            } else {
                sa = p;
            }
            auto sb = a->der;
            auto sc = b->der;

            x = sa;
            y = sb;
            z = sc;

            t1 = x->izq;
            t2 = y->izq;
            t3 = z->izq;
            t4 = z->der;

        }

        if(a->padre){
            y->padre = a->padre;
            if (a->padre->izq.get() == a) a->padre->izq = y;
            else if (a->padre->der.get() == a) a->padre->der = y;
        } else {
            y->padre = nullptr;
            raiz = y;
        }

        y->izq = x;
        y->der = z;
        x->izq = t1;
        x->der = t2;
        if (t1) t1->padre = x.get();
        if (t2) t2->padre = x.get();
        z->izq = t3;
        z->der = t4;
        if (t3) t3->padre = z.get();
        if (t4) t4->padre = z.get();
        x->padre = y.get();
        z->padre = y.get();
    }

    void preorden() const {
        preorden(raiz.get());
        std::cout << std::endl;
    }
    void inorden() const {
        inorden(raiz.get());
        std::cout << std::endl;
    }
    void postorden() const {
        postorden(raiz.get());
        std::cout << std::endl;
    }

private:
    std::shared_ptr<Node<T>> raiz;

    void preorden(const Node<T>* node) const {
        if (!node) return;
        std::cout << node->info << " ";
        preorden(node->izq.get());
        preorden(node->der.get());
    }
    void inorden(const Node<T>* node) const {
        if (!node) return;
        inorden(node->izq.get());
        std::cout << node->info << " ";
        inorden(node->der.get());
    }
    void postorden(const Node<T>* node) const {
        if (!node) return;
        postorden(node->izq.get());
        postorden(node->der.get());
        std::cout << node->info << " ";
    }
};

#endif //ESTUDIOPRACTICA_ARBOLBINARIOBUSQUEDA_H
