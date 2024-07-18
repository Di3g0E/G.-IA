#include <iostream>
#include <memory>
#include <list>
#include <unordered_set>

template <typename T>
class LinkedTree {
public:
    template <typename S>
    class Node {
        friend class LinkedTree;

        S info;
        Node<S>* parent;
        std::list<std::shared_ptr<Node<S>>> children;
        bool operator==(Node<S> rhs) {
            return (info == rhs.info) && (parent == rhs.parent) && (children == rhs.children);
        }
    };

    LinkedTree() : root(nullptr) {}
    LinkedTree(std::shared_ptr<Node<T>> node) : root(node) {}

    bool isEmpty() {return root == nullptr;}

    Node<T>* getRoot() {return root.get();}
    T getElement(Node<T>* node) {return node->info;}
    Node<T>* getParent(Node<T>* node) {return node->parent;}

    bool isRoot(Node<T>* node) {return node == root.get();}
    bool isLeaf(Node<T>* node) {return node->children.size() == 0;}
    bool isInternal(Node<T>* node) {return !isLeaf(node);}

    Node<T>* add(T e, Node<T>* parent = nullptr) {
        if ((parent == nullptr) && (root != nullptr)) {
            std::cout << "Error, root no vacío.\n";
        } else if (parent == nullptr) {
            root = std::make_shared<Node<T>>();
            root->info = e;
            root->parent = nullptr;
            return root.get();
        } else {
            auto aux = std::make_shared<Node<T>>();
            aux->info = e;
            aux->parent = parent;
            parent->children.push_front(aux);
            return aux.get();
        }
        return nullptr;
    }

    std::list<std::shared_ptr<Node<T>>> getChildren(Node<T>* node) { return node->children;}

    LinkedTree<T> cut(Node<T>* node) {
        auto parent = getParent(node);
        std::shared_ptr<Node<T>> shared_node;
            for (auto it = parent->children.begin(); it != parent->children.end();) {
            shared_node = *it;
            if (shared_node.get()  == node) {
                parent->children.erase(it);
                break;
            } else {
                ++it;
            }
        }
        node->parent = nullptr;

        return LinkedTree(shared_node);
    }

    void attach(Node<T>* node, LinkedTree<T> subt) {
        auto subroot = subt.root;
        subroot->parent = node;
        node->children.push_front(subroot);
    }

    bool contains(T e){
        return containsSubT(e, getRoot());
}

    void remove(Node<T>* node){
        if (!root) return;
        if (node == getRoot()){
            auto nc = root->children.size();
            if (nc > 1){
                std::cout << "No se puede borrar la raiz.\n";
                return;
            } else if (nc == 0) {
                root = nullptr;
            } else {root = root->children.front();}
        } else {
            auto it = node->parent->children.begin();
            for(;it != node->parent->children.end();){
                if (*it.get() == node) break;
                ++it;
            }   // Primero hay que calcular la posición de nuestro nodo en la lista de hijos del padre para no tener
                // que recorrer una lista más larga una vez hayamos añadido a los hijos de nuestro nodo a la lista

            for(auto& child: node->children){
                child->parent = node->parent;
                node->parent->children.push_front(child);
            }
            node->parent->children.erase(it);
        }
    }

private:
    bool containsSubT(T e, Node<T>* node){
        if (node == nullptr) return false;
        if (node->info == e) return true;

        for (const auto& n: node->children){
            if (containsSubT(e, n.get())) return true;
        }
        return false;
    }
    std::shared_ptr<Node<T>> root=nullptr;
};

template <typename T>
class LCRSTree {
public:
    template <typename S>
    struct Node {
        S info;
        Node<S>* parent;
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

    Node<T>* getRoot() {return root.get();}
    T getElement(Node<T>* node) {return node->info;}
    Node<T>* getParent(Node<T>* node) {return node->parent;}

    bool isRoot(Node<T>* node) {return node == root.get();}
    bool isLeaf(Node<T>* node) {return node->leftChild == nullptr;}
    bool isInternal(Node<T>* node) {return !isLeaf(node);}

    Node<T>* add(T e, Node<T>* parent = nullptr) {
        if ((parent == nullptr) && (root != nullptr)) {
            std::cout << "Error, root no vacío.\n";
        } else if (parent == nullptr) {
            root = std::make_shared<Node<T>>();
            root->info = e;
            root->parent = nullptr;
            conj.insert(e);
            return root.get();
        } else {
            auto aux = std::make_shared<Node<T>>();
            aux->info = e;
            aux->parent = parent;
            conj.insert(e);
            if (parent->leftChild == nullptr) {
                parent->leftChild = aux;
            } else {
                auto sibling = parent->leftChild;
                while (sibling->RightSibling != nullptr) {
                    sibling = sibling->RightSibling;
                }
                sibling->RightSibling = aux;
            }
            return aux.get();
        }
        return nullptr;
    }

    ChildIterable<T> getChildren(Node<T>* node) { return ChildIterable(node->leftChild);}

    LCRSTree<T> cut(Node<T>* node) {
        auto parent = getParent(node);
        std::shared_ptr<Node<T>> shared_node;
        if (parent->leftChild.get() == node) {
            shared_node = parent->leftChild;
            parent->leftChild = parent->leftChild->RightSibling;
        } else {
            auto aux = parent->leftChild;
            while (aux->RightSibling.get() != node) {
                aux = aux->RightSibling;
            }
            shared_node = aux->RightSibling;
            aux->RightSibling = aux->RightSibling->RightSibling;
        }

        node->parent = nullptr;
        node->RightSibling = nullptr;
        return LCRSTree<T>(shared_node);
    }

    void attach(Node<T>* node, LCRSTree<T> subt) {
        auto subroot = subt.root;
        if (node->leftChild == nullptr) {
            node->leftChild = subroot;
        } else {
            auto aux = node->leftChild;
            while (aux->RightSibling.get() != nullptr) {
                aux = aux->RightSibling;
            }
            aux->RightSibling = subroot;
        }
        subroot->parent = node;
    }

    bool contains(T e){
        //return containsSubT(e, getRoot());
        return conj.contains(e);
    }

    void remove(Node<T>* node){
        if (!root) return;
        if (node == getRoot()){
            auto nc = root->leftChild->RightSibling;
            if (root->leftChild->RightSibling != nullptr){
                std::cout << "No se puede borrar la raiz.\n";
                return;
            } else if (root->leftChild == nullptr) {
                root = nullptr;
            } else {root = root->leftChild;}
        } else {
            auto aux = node->leftChild;
            while (aux->RightSibling != nullptr) {
                aux->parent = node->parent;
                aux = aux->RightSibling;
            }   // Cambia el padre de los hijos del nodo a eliminar
            aux->RightSibling = node->RightSibling; // El último hijo apunta al siguiente hermano de "node"

            if (node->parent->leftChild.get() == node) node->parent->leftChild = node->leftChild;   // Si el nodo a eliminar el LeftChild de su padre entonces su hijo pasará a ser el LeftChild de su padre
            else {
                auto aux = node->parent->leftChild;
                while (aux->RightSibling.get() != node) {
                    aux = aux->RightSibling;
                }
                aux->RightSibling = node->leftChild;} // Si el nodo a eliminar no es el LeftChild de su padre entonces el hermano anterior de "node" apuntará a su hijo como si fuera su RightSibling
        }
    }

private:
    bool containsSubT(T e, Node<T>* node){
        return (node != nullptr)
        && ((node->info == e)
            || (containsSubT(e, node->leftChild))
            || (containsSubT(e, node->RightSibling)));
    }

    std::shared_ptr<Node<T>> root=nullptr;
    std::unordered_set<T> conj;
};

template <typename T>
void printTree(T t) {
    std::cout << "\n\n\nImprimir arbol\n\n";
    std::cout << "Raiz: " << t.getElement(t.getRoot()) << "\n";

    auto hs = t.getChildren(t.getRoot());

    std::cout << "hijos: ";
    for(const auto& h: hs) {
        std::cout << t.getElement(h.get()) << " ";
    }
    std::cout << "\n";

    for(const auto& h: hs) {
        auto ns = t.getChildren(h.get());

        std::cout << "nietos: ";
        for(const auto& n: ns) {
            std::cout << t.getElement(n.get()) << " ";
        }
        std::cout << " | ";
    }
    std::cout << "\n\n\n";

}

int main() {
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

    std::cout << "¿Es root Root?: " << t.isRoot(root) << "\n";
    std::cout << "¿Es h1 Root?: " << t.isRoot(h1) << "\n";
    std::cout << "¿Es n11 Root?: " << t.isRoot(n11) << "\n";
    std::cout << "¿Es hoja root?: " << t.isLeaf(root) << "\n";
    std::cout << "¿Es hoja h2?: " << t.isLeaf(h2) << "\n";
    std::cout << "¿Es hoja n22?: " << t.isLeaf(n22) << "\n";
    std::cout << "¿Es interno Root?: " << t.isInternal(root) << "\n";
    std::cout << "¿Es interno n23?: " << t.isInternal(n23) << "\n";
    std::cout << "¿Es root el padre de h1?: " << (root == t.getParent(h1)) << "\n";
    std::cout << "¿Es root el padre de n11?: " << (root == t.getParent(n11)) << "\n";
    std::cout << "¿Es h2 el padre de n21?: " << (h2 == t.getParent(n21)) << "\n";
    std::cout << "¿Es h2 el padre de n11?: " << (h2 == t.getParent(n11)) << "\n";
    std::cout << "¿Es root el abuelo de h2?: " << (root == t.getParent(t.getParent(h2))) << "\n";
    std::cout << "¿Es root el abuelo de n11?: " << (root == t.getParent(t.getParent(n11))) << "\n";

    auto tcut = t.cut(h1);

    printTree(t);

    printTree(tcut);

    t.attach(root, tcut);

    printTree(t);

    return 0;
}
