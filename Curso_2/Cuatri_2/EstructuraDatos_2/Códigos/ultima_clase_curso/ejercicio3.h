//
// Created by Diego on 03/05/2024.
//

#ifndef ULTIMA_CLASE_CURSO_EJERCICIO3_H
#define ULTIMA_CLASE_CURSO_EJERCICIO3_H

#include <iostream>
#include <list>
#include <unordered_map>

template <typename T, typename S>
class SocialURJC{
public:
    class Node{
        friend class SocialURJC;
        char name;
        std::list<Node> follows;   // Lista de seguidos
        std::list<Node> followers; // Lista de seguidores
    };

    Node newProfile(char name){
        if (g[name] == nullptr){
            auto aux = newNode(name);
            g[name] = aux;
            return &g[name];
        } else {return NULL;}
    }

    void wantToBeFollower(const Node& user_1, const Node& user_2){
        if (g[user_1] == nullptr || g[user_2] == nullptr) { std::cout << "false";}
        Node follower = g[user_1];
        Node follow = g[user_2];
        follow->followers.push_front(follower);
        follower->follows.push_front(follow);
    }

    std::list<Node> followers(const Node& node){
        return node.followers;
    }

    std::list<Node> following(const Node& node){
        return node.follows;
    }

    std::list<Node> suggestions(const Node& node){
        std::list<Node> suggestions;
        for (const Node& following : node.follows) {
            bool found = false;
            for (const Node& nodeInFollows : node.follows) {
                if (nodeInFollows == following) {
                    suggestions.push_front(following);
                    found = true;
                    break;
                }
            }
            if (found) { break;}
        }
        return suggestions;
    }

    std::list<Node> suspiciousBot(){
        std::list<Node> suspiciousBot;
        for (const auto& e: g){
            if (e.second.followers.size() == 0) suspiciousBot.push_front(e);
        }
        return suspiciousBot;
    }

    std::list<Node> cleanBots(){
        std::list<Node> bots = suspiciousBot();
        if (bots.size() != 0){
            for (auto &e: bots) {
                g.erase(e);
            }
        } else {}
        cleanBots()
        return bots;
    }

    Node newNode(char name, std::list<Node> follows = std::list<Node>(), std::list<Node> followers = std::list<Node>()){
        Node aux;
        aux->name = name;
        aux->follows = follows;
        aux->followers = followers;
        return aux;
    }


private:
    std::unordered_map<T, Node> g;
};

#endif //ULTIMA_CLASE_CURSO_EJERCICIO3_H

#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T, typename W>
class BasicGraph {
public:
    void addNode(T node) {
        nodes[node] = {};
    }

    void setEdge(T sourceNode, T targetNode, W weight) {
        nodes[sourceNode][targetNode] = weight;
        nodes[targetNode][sourceNode] = weight; // Grafo no dirigido
    }

    const std::unordered_map<T, W>& getEdges(T node) const {
        return nodes[node];
    }

    // No puede ser const porque puede crear la arista vacia si no existe
    W getEdge(T sourceNode, T targetNode) {
        return nodes[sourceNode][targetNode];
    }

    void removeNode(T node) {
        auto& edges = nodes[node];
        for (const auto& [targetNode, weight] : edges) {
            nodes[targetNode].erase(node);
        }
        nodes.erase(node);
    }

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

int main() {
    BasicGraph<int, int> graph;

    // Agregar nodos
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    // Agregar aristas
    graph.setEdge(1, 2, 42);
    graph.setEdge(1, 3, 43);
    graph.setEdge(1, 4, 44);
    graph.setEdge(1, 5, 44);
    graph.setEdge(2, 3, 37);
    graph.setEdge(3, 4, 34);
    graph.setEdge(4, 5, 54);

    // Mostrar grafo completo
    for (const auto& [node, edges] : graph) {
        std::cout << "Aristas del nodo " << node << ":" << "\n";
        for (const auto& [targetNode, weight] : edges) {
            std::cout << "  - Nodo " << targetNode << ": " << ((weight != 0) ? "Conectado" : "No conectado") << "\n";
        }
    }

    graph.removeNode(3);

    std::cout << "***********************\n";

    // Mostrar grafo sin nodo 3
    for (const auto& [node, edges] : graph) {
        std::cout << "Aristas del nodo " << node << ":" << "\n";
        for (const auto& [targetNode, weight] : edges) {
            std::cout << "  - Nodo " << targetNode << ": " << ((weight != 0) ? "Conectado" : "No conectado") << "\n";
        }
    }

    std::cout << "***********************\n";

    // GetEdges muestra la arista si existe y sino la crea "vacia"
    std::cout << "Node 1 - Node 2: " << graph.getEdge(1, 2) << "\n";
    std::cout << "Node 2 - Node 5: " << graph.getEdge(2, 5) << "\n";

    return 0;
}
