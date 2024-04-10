#include <iostream>
#include <unordered_map>

template <typename T, typename W>
class Grafo_basico{
public:
    void addNode(const T& node) {
        nodes[node] = {};
    }

    void setEdge(const T& node1, const T& node2, const W& peso) {
        nodes[node1][node2] = peso;
        nodes[node2][node1] = peso;
    }

    W getEdge(const T& node1, const T& node2) {
        return nodes[node1][node2];
    }

    const std::unordered_map<T, W>& getEdges(const T& node) {
        return nodes[node];
    }

    void removeNode(const T& node) {
        for (auto& [otherNode, _] : nodes[node]) {  // Recorre el mapa de adyacencias del nodo que queremos eliminar
            nodes[otherNode].erase(node);
        }
        nodes.erase(node);
    }

    auto begin() {return nodes.begin();}
    auto end() {return nodes.end();}

private:
    std::unordered_map<T, std::unordered_map<T, W>> nodes;
};

int main() {
    Grafo_basico<int, float> grafo;

    // Añadir nodos
    grafo.addNode(1);
    grafo.addNode(2);
    grafo.addNode(3);
    grafo.addNode(4);
    grafo.addNode(5);

    // Añadir aristas
    grafo.setEdge(1, 2, 42);
    grafo.setEdge(1, 3, 132);
    grafo.setEdge(1, 4, 45);
    grafo.setEdge(1, 5, 76);
    grafo.setEdge(2, 3, 14);
    grafo.setEdge(3, 4, 98);
    grafo.setEdge(4, 5, 23);

    // Mostrar grafo
    for (const auto& [node, edges] : grafo){
        std::cout << node << '\n';
        for (const auto& [targetNode, weight] : edges){
            std::cout << "  - Nodo " << targetNode << ": " << ((weight != 0) ? "Conectado\n" : "No conectado\n");
        }
    }

    // Eliminar el nodo 2
    grafo.removeNode(2);

    return 0;
}
