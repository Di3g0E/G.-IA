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

    const std::unordered_map<T, W>& getEdges(T node) {
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
    std::unordered_map<T, std::unordered_map<typename T::ID, W>> nodes;
    std::unordered_map<typename T::ID, T> reverse;
};

struct City {
    std::string name;
    int population;
    int surface;

    using ID = std::string;
    ID getID() {return ISBN;}

    auto operator<=>(const City& rhs) const = default;
};

template <>
struct std::hash<City> {
    std::size_t operator()(const City& city) const {
        return ((std::hash<std::string>()(city.name)
                 ^ (std::hash<int>()(city.population) << 1)) >> 1)
               ^ (std::hash<float>()(city.surface) << 1);
    }
};





#endif //ESTUDIOPRACTICA_GRAFOS_H