//
// Created by Diego on 24/05/2024.
//

#ifndef REPASOCOMPLETO_BASICGRAPH_H
#define REPASOCOMPLETO_BASICGRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <stack>

template <typename T, typename W>
class BasicGraph{
public:
    void addNode(T node) { nodes[node] = {}; }

    void setEdge(T origen, T dest, W val) {
        nodes[origen][dest] = val;
        nodes[dest][origen] = val;
    }

    const std::unordered_map<T, W>& getEdges(T node) const { return nodes[node]; }

    W getVal(T origen, T dest) { return nodes[origen][dest]; }

    void removeNode(T node) {
        auto& edges = nodes[node];
        for(const auto& [dest, val]: edges){
            nodes[dest].erase(node);
        }
        nodes.erase(node);
    }

    auto begin() { return nodes.begin(); }

    auto end() { return nodes.end(); }

private:
    std::unordered_map<T, std::unordered_map<T, W>> nodes;
};

template <typename T>
class ProfundidadIterator{
public:
    ProfundidadIterator() :graph(nullptr), node(nullptr) {}

    ProfundidadIterator(T graph, typename T::Node<typename T::type>* start) :graph(graph), node(start) {
        if(node){
            pila.push(node);
            visitados.insert(node);
        }
    }

    ProfundidadIterator& operator++(){
        if(!pila.empty()){
            node = pila.top();
            pila.pop();
            for(auto vecinos: )
        }
    }

private:
    T* graph;
    typename T::Node<typename T::type>* node;
    std::stack<typename T::Node<typename T::type>*> pila;
    std::unordered_set<typename T::Node<typename T::type>*> visitados;
};

#endif //REPASOCOMPLETO_BASICGRAPH_H
