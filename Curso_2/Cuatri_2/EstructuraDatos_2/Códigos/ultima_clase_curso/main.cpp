#include <memory>
#include <stack>
#include <deque>
#include <queue>

#include <iostream>

template <typename T>
class LinkedBinaryTree {
public:
    using type = T;
    template <typename S>
    class Node {
        friend class LinkedBinaryTree;
        S info;
        Node<S>* parent;
        std::shared_ptr<Node<S>> left;
        std::shared_ptr<Node<S>> right;
    };

    T getElement(Node<T>* node) const {return (node->info);}
    Node<T>* getRoot()                   const {return root.get();}
    Node<T>* getParent(Node<T>* node)     const {return (node->parent);}
    Node<T>* getLeftChild(Node<T>* node) const {return (node->left.get());}
    Node<T>* getRightChild(Node<T>* node) const {return (node->right.get());}

    bool isEmpty() {return root == nullptr;}
    bool isRoot(Node<T>* node) const {return (node == root.get());}
    bool isLeaf(Node<T>* node) const {return ((node->left == nullptr) && (node->right == nullptr));}
    bool isInternal(Node<T>* node) const {return !isLeaf(node);}

    Node<T>* addRoot(T e) {
        root = std::make_shared<Node<T>>();
        root->info = e;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        return (root.get());
    }
    Node<T>* addLeft(T e, Node<T>* parent) {
        parent->left = std::make_shared<Node<T>>();
        parent->left->info = e;
        parent->left->parent = parent;
        parent->left->left = nullptr;
        parent->left->right = nullptr;
        return (parent->left.get());
    }
    Node<T>* addRight(T e, Node<T>* parent) {
        parent->right = std::make_shared<Node<T>>();
        parent->right->info = e;
        parent->right->parent = parent;
        parent->right->left = nullptr;
        parent->right->right = nullptr;
        return (parent->right.get());
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};

template <typename T>
class PreorderIterator {
public:
    PreorderIterator() : t(), p() {}
    PreorderIterator(T tree) : t(tree), p() {p.push(t.getRoot());}

    PreorderIterator& operator++() {
            auto e = p.top();
            p.pop();
            auto d = t.getRightChild(e);
            if (d)
                p.push(d);
            auto i = t.getLeftChild(e);
            if (i)
                p.push(i);
            return *this;
        }

    PreorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getElement(p.top());
    }

    bool operator!=(const PreorderIterator& other) {
        //std::cout << "Es empty p" << p.empty() << "\n";
        //std::cout << "Es empty other" << other.p.empty() << "\n";
        bool d = (p.empty() != other.p.empty());
        //std::cout << "Distinto: " << d << "\n";
        return d;
    }
private:
    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};

template <typename T>
class InorderIterator {
public:
    InorderIterator() : t(), c() {}
    InorderIterator(T tree) : t(tree), c() {traverseLeft(t.getRoot());}

    InorderIterator& operator++() {
        auto child = t.getRightChild(c[0]);
        c.pop_front();
        traverseLeft(child);
        return *this;
    }

    InorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getElement(c[0]);
    }

    bool operator!=(const InorderIterator& other) {
        bool d = (c.empty() != other.c.empty());
        return d;
    }
private:
    void traverseLeft(typename T::Node<typename T::type>* node) {
        while (node) {
            c.push_front(node);
            node = t.getLeftChild(node);
        }
    }

    T t;
    std::deque<typename T::Node<typename T::type>*> c;
};

template <typename T>
class PosorderIterator {
public:
    PosorderIterator() : t(), p() {}
    PosorderIterator(T tree) : t(tree), p() {traverseLeftLeaf(t.getRoot());}

    PosorderIterator& operator++() {
        auto e = p.top();
        p.pop();

        if ((t.getParent(e)) && (e == t.getLeftChild(p.top()))) {
            traverseLeftLeaf(t.getRightChild(p.top()));
        }
        return *this;
    }

    PosorderIterator operator++(int) {
        auto tmp(*this);
        operator++();
        return tmp;
    }

    auto operator*() {
        return t.getElement(p.top());
    }

    bool operator!=(const PosorderIterator& other) {
        bool d = (p.empty() != other.p.empty());
        return d;
    }
private:
    void traverseLeftLeaf(typename T::Node<typename T::type>* node) {
        while (node) {
            p.push(node);
            auto aux = node;
            node = t.getLeftChild(node);
            if (!node) node = t.getRightChild(aux);
        }
    }

    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};


template <typename T, typename I>
class Iterable {
public:
    Iterable(T begin) : b(I(begin)), e(I()) {}

    auto begin() { return b; }

    auto end() { return e; }

private:
    I b;
    I e;
};

template <typename T>
class LeafeIterator{
public:
    LeafeIterator() : t(), p() {}
    LeafeIterator(T tree) : t(tree), p() {p.push(t.getRoot());}

    LeafeIterator& operator++() {
        auto e = p.top();
        p.pop();
        auto d = t.getRightChild(e);
        if (d)
            p.push(d);
        auto i = t.getLeftChild(e);
        if (i)
            p.push(i);
        return *this;
    }

    LeafeIterator operator++(int) {
        auto tmp(*this);
        operator++();
        // Añadir aquí la implementación del ejercicio 1
        return tmp;
    }

    auto operator*() {
        return t.getElement(p.top());
    }

    bool operator!=(const LeafeIterator& other) {
        //std::cout << "Es empty p" << p.empty() << "\n";
        //std::cout << "Es empty other" << other.p.empty() << "\n";
        bool d = (p.empty() != other.p.empty());
        //std::cout << "Distinto: " << d << "\n";
        return d;
    }

private:
    T t;
    std::stack<typename T::Node<typename T::type>*> p;
};


template <typename T>
class LinkedTernaryTree {
public:
    using type = T;
    template <typename S>
    class Node {
        friend class LinkedTernaryTree;
        S info;
        Node<S>* parent;
        std::shared_ptr<Node<S>> left;
        std::shared_ptr<Node<S>> middle;
        std::shared_ptr<Node<S>> right;
    };

    T getElement(Node<T>* node) const {return (node->info);}
    Node<T>* getRoot()                   const {return root.get();}
    Node<T>* getParent(Node<T>* node)     const {return (node->parent);}
    Node<T>* getLeftChild(Node<T>* node) const {return (node->left.get());}
    Node<T>* getMedioChild(Node<T>* node) const {return (node->middle.get());}
    Node<T>* getRightChild(Node<T>* node) const {return (node->right.get());}

    bool hasMiddle (Node<T>* node) {return node->middle.get() != nullptr;}
    bool isEmpty() {return root == nullptr;}
    bool isRoot(Node<T>* node) const {return (node == root.get());}
    bool isLeaf(Node<T>* node) const {return ((node->left == nullptr) && (node->right == nullptr));}
    bool isInternal(Node<T>* node) const {return !isLeaf(node);}

    Node<T>* addRoot(T e) {
        root = std::make_shared<Node<T>>();
        root->info = e;
        root->parent = nullptr;
        root->left = nullptr;
        root->middle = nullptr;
        root->right = nullptr;
        return (root.get());
    }
    Node<T>* addLeft(T e, Node<T>* parent) {
        parent->left = std::make_shared<Node<T>>();
        parent->left->info = e;
        parent->left->parent = parent;
        parent->left->left = nullptr;
        parent->left->right = nullptr;
        return (parent->left.get());
    }
    Node<T>* addMedio(T e, Node<T>* parent) {
        parent->middle = std::make_shared<Node<T>>();
        parent->middle->info = e;
        parent->middle->parent = parent;
        parent->middle->left = nullptr;
        parent->middle->middle = nullptr;
        parent->middle->right = nullptr;
        return (parent->middle.get());
    }
    Node<T>* addRight(T e, Node<T>* parent) {
        parent->right = std::make_shared<Node<T>>();
        parent->right->info = e;
        parent->right->parent = parent;
        parent->right->left = nullptr;
        parent->right->right = nullptr;
        return (parent->right.get());
    }

    void remove(Node<T>* node) {
        if (root == nullptr) return;
        if (node->left == nullptr || node->middle == nullptr || node->right == nullptr) {root = nullptr;}
        if ((node->left != nullptr && node->middle == nullptr && node->right == nullptr)
        || (node->left == nullptr && node->middle != nullptr && node->right == nullptr)
        || (node->left == nullptr && node->middle == nullptr && node->right != nullptr)) {
            if (node->left != nullptr) { // implementar resto}
            else if (node->middle != nullptr) { // implementar resto}
            else if (node->right) != nullptr { // implementar resto}
        } // implementar resto
    }

private:
    std::shared_ptr<Node<T>> root = nullptr;
};




int main() {
    std::cout << "Hola Mundo!\n";

    LinkedBinaryTree<int> t;

    auto r = t.addRoot(42);
    auto hi = t.addLeft(15, r);
    auto hd = t.addRight(60, r);
    auto hii = t.addLeft(7, hi);
    auto hid = t.addRight(20, hi);
    auto hdi = t.addLeft(50, hd);
    auto hdd = t.addRight(67, hd);

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, PreorderIterator<LinkedBinaryTree<int>>> preit(t);
    for (int i : preit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, InorderIterator<LinkedBinaryTree<int>>> inoit(t);
    for (int i : inoit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    std::cout << '\n';

    Iterable<LinkedBinaryTree<int>, PosorderIterator<LinkedBinaryTree<int>>> posit(t);
    for (int i : posit) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
