//
// Created by Diego on 23/02/2024.
//

#ifndef LISTASYARBOLES_NARYTREE_H
#define LISTASYARBOLES_NARYTREE_H


#include <iostream>
#include <memory>
#include <list>

template <typename T>
class LinkedTree {
        public:
        template <typename S>
        struct Node {
            S info;
            std::shared_ptr<Node<S>> parent;
            std::list<std::shared_ptr<Node<S>>> children;
            bool operator==(Node<S> rhs) {
                return (info == rhs.info) && (parent == rhs.parent) && (children == rhs.children);
            }
        };

        LinkedTree() : root(nullptr) {}
        LinkedTree(std::shared_ptr<Node<T>> node) : root(node) {}

        bool isEmpty() {return root == nullptr;}

        std::shared_ptr<Node<T>> getRoot() {return root;}
        T getElement(Node<T> node) {return node.info;}
        std::shared_ptr<Node<T>> getParent(Node<T> node) {return node.parent;}

        bool isRoot(Node<T> node) {return node == *(root);}
        bool isLeaf(Node<T> node) {return node.children.size() == 0;}
        bool isInternal(Node<T> node) {return !isLeaf(node);}

        std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr) {
            if ((parent == nullptr) && (root != nullptr)) {
                std::cout << "Error, root no vacío.\n";
            } else if (parent == nullptr) {
                root = std::make_shared<Node<T>>(e, nullptr);
                // root = std::make_shared<Node<T>>();
                // root->info = e;
                return root;
            } else {
                auto aux = std::make_shared<Node<T>>(e, parent);
                parent->children.push_front(aux);
                return aux;
            }
            return nullptr;
        }

        std::list<std::shared_ptr<Node<T>>> getChildren(Node<T> node) { return node.children;}

        LinkedTree<T> cut(std::shared_ptr<Node<T>> node) {
            auto parent = getParent(*node);
            parent->children.remove(node);
            node->parent = nullptr;

            return LinkedTree(node);
        }

        void attach(std::shared_ptr<Node<T>> node, LinkedTree<T> subt) {
            auto subroot = subt.getRoot();
            subroot->parent = node;
            node->children.push_front(subroot);
        }


        private:
        std::shared_ptr<Node<T>> root=nullptr;
};

template <typename T>
class LCRSTree {
        public:
        template <typename S>
        struct Node {
            S info;
            std::shared_ptr<Node<S>> parent;
            std::shared_ptr<Node<S>> leftChild;
            std::shared_ptr<Node<S>> RightSibling;

            bool operator==(Node<S> rhs) {
                return (parent == rhs.parent) && (leftChild == rhs.leftChild) && (RightSibling == rhs.RightSibling);
            }
        };

        class ChildIterator {
            public:
            ChildIterator(std::shared_ptr<Node<T>> node) : it(node) {}

            ChildIterator& operator++() {
                it = it->RightSibling;
                return *this;
            }

            ChildIterator operator++(int) {
                auto tmp(*this);
                operator++();
                return tmp;
            }

            auto operator*() {
                return it;
            }

            bool operator!=(const ChildIterator& other) {
                return it != other.it;
            }

            private:
            std::shared_ptr<Node<T>> it;
        };

        template <typename S>
        class ChildIterable {
            public:
            ChildIterable(std::shared_ptr<Node<S>> node) : node(node) {}

            auto begin() { return ChildIterator(node); }

            auto end() { return ChildIterator(nullptr); }

            private:
            std::shared_ptr<Node<S>> node=nullptr;
        };

        LCRSTree() : root(nullptr) {}
        LCRSTree(std::shared_ptr<Node<T>> node) : root(node) {}

        bool isEmpty() {return root == nullptr;}

        std::shared_ptr<Node<T>> getRoot() {return root;}
        T getElement(Node<T> node) {return node.info;}
        std::shared_ptr<Node<T>> getParent(Node<T> node) {return node.parent;}

        bool isRoot(Node<T> node) {return node == *(root);}
        bool isLeaf(Node<T> node) {return node.leftChild == nullptr;}
        bool isInternal(Node<T> node) {return !isLeaf(node);}

        std::shared_ptr<Node<T>> add(T e, std::shared_ptr<Node<T>> parent = nullptr) {
            if ((parent == nullptr) && (root != nullptr)) {
                std::cout << "Error, root no vacío.\n";
            } else if (parent == nullptr) {
                root = std::make_shared<Node<T>>(e, nullptr);
                // root = std::make_shared<Node<T>>();
                // root->info = e;
                return root;
            } else {
                auto aux = std::make_shared<Node<T>>(e, parent);
                if (parent->leftChild == nullptr) {
                    parent->leftChild = aux;
                } else {
                    auto sibling = parent->leftChild;
                    while (sibling->RightSibling != nullptr) {
                        sibling = sibling->RightSibling;
                    }
                    sibling->RightSibling = aux;
                }
                return aux;
            }
            return nullptr;
        }

        ChildIterable<T> getChildren(Node<T> node) { return ChildIterable(node.leftChild);}

        LCRSTree<T> cut(std::shared_ptr<Node<T>> node) {
            auto parent = getParent(*node);

            if (parent->leftChild == node) {
                parent->leftChild = parent->leftChild->RightSibling;
            } else {
                auto aux = parent->leftChild;
                while (aux->RightSibling != node) {
                    aux = aux->RightSibling;
                }
                aux->RightSibling = aux->RightSibling->RightSibling;
            }

            node->parent = nullptr;
            node->RightSibling = nullptr;
            return LCRSTree<T>(node);
        }

        void attach(std::shared_ptr<Node<T>> node, LCRSTree<T> subt) {
            auto subroot = subt.getRoot();
            if (node->leftChild == nullptr) {
                node->leftChild = subroot;
            } else {
                auto aux = node->leftChild;
                while (aux->RightSibling != nullptr) {
                    aux = aux->RightSibling;
                }
                aux->RightSibling = subroot;
            }
            subroot->parent = node;
        }


        private:
        std::shared_ptr<Node<T>> root=nullptr;
};

template <typename T>
void printTree(LinkedTree<T> t) {
    std::cout << "\n\n\nImprimir arbol\n\n";
    std::cout << "Raiz: " << t.getElement(*(t.getRoot())) << "\n";

    auto hs = t.getChildren(*(t.getRoot()));

    std::cout << "hijos: ";
    for(const auto& h: hs) {
        std::cout << t.getElement(*h) << " ";
    }
    std::cout << "\n";

    for(const auto& h: hs) {
        auto ns = t.getChildren(*h);

        std::cout << "nietos: ";
        for(const auto& n: ns) {
            std::cout << t.getElement(*n) << " ";
        }
        std::cout << " | ";
    }
    std::cout << "\n\n\n";

}

template <typename T>
void printTree(LCRSTree<T> t) {
    std::cout << "\n\n\nImprimir arbol\n\n";
    std::cout << "Raiz: " << t.getElement(*(t.getRoot())) << "\n";

    auto hs = t.getChildren(*(t.getRoot()));

    std::cout << "hijos: ";
    for(const auto& h: hs) {
        std::cout << t.getElement(*h) << " ";
    }
    std::cout << "\n";

    for(const auto& h: hs) {
        auto ns = t.getChildren(*h);

        std::cout << "nietos: ";
        for(const auto& n: ns) {
            std::cout << t.getElement(*n) << " ";
        }
        std::cout << " | ";
    }
    std::cout << "\n\n\n";

}

int main()
{
    std::cout<<"Hello World";

    //LinkedTree<int> t;
    LCRSTree<int> t;

    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    auto root = t.add(42);
    auto h1 = t.add(37, root);
    auto h2 = t.add(3, root);
    auto n11 = t.add(17, h1);
    auto n21 = t.add(9, h2);
    auto n22 = t.add(27, h2);
    auto n23 = t.add(81, h2);

    std::cout << "Es vacio: " << t.isEmpty() << "\n";

    printTree(t);

    std::cout << "¿Es root Root?: " << t.isRoot(*root) << "\n";
    std::cout << "¿Es h1 Root?: " << t.isRoot(*h1) << "\n";
    std::cout << "¿Es n11 Root?: " << t.isRoot(*n11) << "\n";
    std::cout << "¿Es hoja root?: " << t.isLeaf(*root) << "\n";
    std::cout << "¿Es hoja h2?: " << t.isLeaf(*h2) << "\n";
    std::cout << "¿Es hoja n22?: " << t.isLeaf(*n22) << "\n";
    std::cout << "¿Es interno Root?: " << t.isInternal(*root) << "\n";
    std::cout << "¿Es interno n23?: " << t.isInternal(*n23) << "\n";
    std::cout << "¿Es root el padre de h1?: " << (root == t.getParent(*h1)) << "\n";
    std::cout << "¿Es root el padre de n11?: " << (root == t.getParent(*n11)) << "\n";
    std::cout << "¿Es h2 el padre de n21?: " << (h2 == t.getParent(*n21)) << "\n";
    std::cout << "¿Es h2 el padre de n11?: " << (h2 == t.getParent(*n11)) << "\n";
    std::cout << "¿Es root el abuelo de h2?: " << (root == t.getParent(*(t.getParent(*h2)))) << "\n";
    std::cout << "¿Es root el abuelo de n11?: " << (root == t.getParent(*(t.getParent(*n11)))) << "\n";

    auto tcut = t.cut(h1);

    printTree(t);

    printTree(tcut);

    t.attach(root, tcut);

    printTree(t);

    return 0;
}

#endif //LISTASYARBOLES_NARYTREE_H
