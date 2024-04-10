#include <iostream>
#include "ListaEnlazadaSimple.h"
#include "ArbolNario.h"
#include "LinkedBinaryTree.h"



int main() {
    /*
    ListaEnlazadaSimple<int> l;
    l.insertar(3);
    l.insertar(2);
    l.insertar(4);
    l.insertar(3);

    l.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<l.primero()<<'\n';

    l.resto();

    l.imprimir();
    std::cout<<'\n';

    ListaEnlazadaSimple<std::string> q;
    q.insertar("hola");
    q.insertar("adios");
    q.insertar("Paco");
    q.insertar("Juanillo");

    q.imprimir();

    std::cout<<"El primer elemento de la lista es: "<<q.primero()<<'\n';

    q.resto();

    q.imprimir();
     */ // ListaEnlazadaSimple

    ///*
    LinkedBinaryTree<int> tree;

    auto root = tree.addRoot(1);
    auto l_1 = tree.addLeft(2, root);
    auto r = tree.addRight(3, root);
    tree.addLeft(4, l_1);
    tree.addRight(5, l_1);

    std::cout<<"La raiz del arbol es: "<< tree.getElement(tree.getRoot())<<"\n";
    std::cout<<"El hi del arbol es: "<<tree.getElement(tree.getLeftChild(root))<<"\n";
    std::cout<<"El hd del arbol es: "<<tree.getElement(tree.getRightChild(root))<<"\n";
    std::cout<<"El hihi del arbol es: "<<tree.getElement(tree.getLeftChild(tree.getLeftChild(root)))<<"\n";
    std::cout<<"El hdhi del arbol es: "<<tree.getElement(tree.getRightChild(tree.getLeftChild(root)))<<"\n";
    std::cout<<"El arbol esta vacio: "<<tree.isEmpty()<<"\n";
    std::cout<<"La raiz es hoja: "<<tree.isLeaf(root)<<"\n";
    std::cout<<"El hi es interno: "<<tree.isInternal(tree.getLeftChild(root))<<"\n";
    std::cout<<"Es la raiz el padre del hi: "<<tree.isRoot(tree.getParent(tree.getLeftChild(root)))<<"\n";
    std::cout<<"Es la raiz el padre del hihi: "<<tree.isRoot(tree.getParent(tree.getLeftChild(tree.getLeftChild(root))))<<"\n";
    //*/  // LinkedBinaryTree

    return 0;
}