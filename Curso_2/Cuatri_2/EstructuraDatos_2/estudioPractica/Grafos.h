//
// Created by Diego on 05/04/2024.
//

#ifndef ESTUDIOPRACTICA_GRAFOS_H
#define ESTUDIOPRACTICA_GRAFOS_H

#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T, typename W>
class BasicGraph {
public:
    void addNode(T node) {
        nodes[node] = {};
    }   // Añadir nodo

    void setEdge(T sourceNode, T targetNode, W weight) {
        nodes[sourceNode][targetNode] = weight;
        nodes[targetNode][sourceNode] = weight; // Grafo no dirigido
    }   // Añadir arista (con peso)

    const std::unordered_map<T, W>& getEdges(T node) const {
        return nodes[node];
    }   // Devolver las aristas conectadas a otro nodo

    // No puede ser const porque puede crear la arista vacía si no existe
    W getEdge(T sourceNode, T targetNode) {
        if (nodes[sourceNode][targetNode]){
            return nodes[sourceNode][targetNode];
        } else return 0;
    }   // Devolver el peso

    void removeNode(T node) {
        auto& edges = nodes[node];
        for (const auto& [targetNode, weight] : edges) {
            nodes[targetNode].erase(node);
        }
        nodes.erase(node);
    }   // Eliminar nodo

    auto begin() {return nodes.begin();}
    auto end() {return nodes.end();}

private:
    std::unordered_map<T, std::unordered_map<T, W>> nodes;
};

struct city {
    std::string name;
    int population;
    int suface;
};



#endif //ESTUDIOPRACTICA_GRAFOS_H
